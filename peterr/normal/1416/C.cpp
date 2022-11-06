#include <bits/stdc++.h>

using namespace std;

const int LOGN = 30;

long long solve(vector<int> &vec, int ind, vector<int> &a, vector<int> &b)
{
    long long ans = 0;
    int big = 0;
    for (int x : vec)
    {
        if (x & (1 << ind))
        {
            a.push_back(x);
            big++;
        }
        else
        {
            b.push_back(x);
            ans += big;
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<vector<int>> vec;
    vector<vector<int>> vec2;
    vec.push_back(vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        cin >> vec[0][i];
    }
    int x = 0;
    long long ans = 0;
    for (int i = LOGN - 1; i >= 0; i--)
    {
        //cout << "i " << i << endl;
        long long total = 0;
        long long temp = 0;
        for (vector<int> v : vec)
        {
            vector<int> a;
            vector<int> b;
            //total += (int) v.size() * (v.size() - 1) / 2;
            temp += solve(v, i, a, b);
            if (a.size())
                vec2.push_back(a);
            if (b.size())
                vec2.push_back(b);
            total += ((long long) a.size() * b.size());
        }
        if (total - temp < temp)
        {
            x ^= 1 << i;
            temp = total - temp;
        }
        ans += temp;
        vec = vec2;
        //move(vec2.begin(), vec2.end(), vec.begin());
        vec2.clear();
    }
    cout << ans << " " << x << "\n";
    return 0;
}