#include <bits/stdc++.h>
using namespace std;
using lint = long long;

lint N;
vector<pair<lint, lint>> C;
vector<pair<lint, lint>> P;

inline lint cross(pair<lint, lint> a, pair<lint, lint> b) {
    return a.first * b.second - a.second * b.first;
}

bool angle(pair<lint, lint> a, pair<lint, lint> b) {
    if (a.second == 0 && a.first > 0) 
        return true;
    if (b.second == 0 && b.first > 0) 
        return false;
    if (a.second * b.second < 0) 
        return a.second > b.second;

    return cross(a, b) > 0;
}

lint solve(int v) { // take v as center, than count how many configurations yield v as good
    P.clear();

    for (int i = 0; i < N; i++) if (i != v) 
        P.emplace_back(C[i].first - C[v].first, C[i].second - C[v].second);
    
    sort(P.begin(), P.end(), angle);

    lint active = 0, res = 0;

    for (int i = 0; i < N - 1; i++) {
        active = max(active, i + 1ll);

        while (active < 2 * (N - 1) && cross(P[i], P[active % (N - 1)]) > 0) 
            active++;
        
        res += (active - i - 1) * (active - i - 2) / 2;
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    C.resize(N);
    for (int i = 0; i < N; i++)
        cin >> C[i].first >> C[i].second;

    lint good_points = 0;

    for (int i = 0; i < N; i++)
        good_points += solve(i);

    good_points -= N * (N - 1) * (N - 2) * (N - 3) / 12; // 4P + 3Q

    lint P = good_points - N * (N - 1) * (N - 2) * (N - 3) / 24; // convex quadrilateral
    lint Q = N * (N - 1) * (N - 2) * (N - 3) / 24 - P; // concave quadrilateral
    cout << (Q * (N - 4)) / 2 << "\n"; // somewhow this formula works...
    /*
        Logic: For every quadrilaterals, if there exists a point inside it, the point
        must be in 2 of the triangles. Thus we can simply multiply Triangle * (N - 4) / 2.

        Calculating the number of concave quadrilaterals is equal to the number of points
        in a subset of a triangle.
    
    */
    return 0;
}

/*
Explanation in comments:

https://codeforces.com/blog/entry/72725


AwakeAnay
2 hours ago, # | Add to favourites  Vote: I like it +13 Vote: I do not like it
Here's a cool reduction I made for E:

Claim: Find the sum of number of points in all possible triangles in the given set. Divide this by 2 and multiply by n4, that's the answer.

Proof: For any castle of 4 points and a point P which lies inside it, consider all the 4 triangles made by taking the castle points 3 at a time. Out of these 4 triangles, P will lie in exactly 2 of them. Conversely, consider any triangle and any point P lying inside it. If you add any of the other n4 points to make the triangle into a quadrilateral, you will get a valid castle of the triangle points and this new point which will protect P.

Thus, we have proven a two-one bijection between these two quantities.

Now, if you could find the sum of number of points lying inside each triangle in O(n2), you have solved the problem!

 Reply

GyojunYoun
32 minutes ago, # ^ | Add to favourites Rev. 3    Vote: I like it +4 Vote: I do not like it
Goal : A point p and a set of N points S are given. We want to compute the number of triangles containing p.

We can easily know that the answer is "N(N1)(N2)/6  (the number of triangles which do NOT contain p)". If the triangle s1s2s3 does not contain p, then there is a straight line l that splits p and three points s1, s2 and s3. Thus, we can design the algorithm below:

Consider the line l, which passes the point p.

Rotate l about p.

When l touches a point of S, compute the number of points that are on the left side of l.

Let k be the number, then add (k1)(k2)/2 to the answer.

Do the step 2. to 4. until l is rotated by 360 deg.

The naive algorithm is O(N2). But you can do it in O(NlgN) with sorting points S about p  something like ccw-sort

Now, whole the problem can be solved. Just do the steps above about all the N points. The time complexity is O(N2lgN).

 Reply

*/