#include <bits/stdc++.h>
#define ll long long


using namespace std;

vector <int> v;
vector <int> vec;

inline int query(vector <int> a) {
    cout << "?" << " " << a.size() << " ";
    for(auto it : a)
        cout << it << " ";
    cout << endl;
    fflush(stdout);
    int ans;
    cin >> ans;
    return ans;
}

bool eq[20];

int main() {
    //fstream cin("A.in");
    //ofstream cout("A.out");
    int n, x, y, bit, ans, i;
    ios::sync_with_stdio(false);
    cin >> n >> x >> y;
    for(bit = 0; (1 << bit) <= n; bit++) {
        v.clear();
        for(i = 1; i <= n; i++)
            if(i & (1 << bit))
                v.push_back(i);
        ans = query(v);
        if(v.size() % 2 == 0) {
            if(ans == 0)
                eq[bit] = 1;
            else
                eq[bit] = 0;
        }
        else {
            if(ans == y)
                eq[bit] = 0;
            else
                eq[bit] = 1;
        }
    }
    bit = 0;
    while(eq[bit] == 1)
        bit++;
    int cnt = 0;
    for(i = 1; i <= n; i++)
        if(i & (1 << bit))
           cnt++;
    if(cnt <= n / 2) {
         for(i = 1; i <= n; i++)
            if(i & (1 << bit))
               vec.push_back(i);
    }
    else {
         for(i = 1; i <= n; i++)
            if((i & (1 << bit)) == 0)
               vec.push_back(i);
    }
    int rez = -1;
    for(int pas = 1 << 9; pas; pas >>= 1)
        if(rez + pas < vec.size()) {
            v.clear();
            for(i = 0; i <= rez + pas; i++)
                v.push_back(vec[i]);
            ans = query(v);
            if(((rez + pas) % 2 == 0 && ans == x) || ((rez + pas) % 2 == 1 && ans == 0))
               rez += pas;
        }
    int p1 = vec[rez + 1];
    int p2 = 0;
    for(bit = 0; (1 << bit) <= n; bit++)
        if(eq[bit] == 1)
          p2 += (1 << bit) * ((p1 & (1 << bit)) > 0);
        else
          p2 += (1 << bit) * ((p1 & (1 << bit)) == 0);
    if(p1 > p2)
        swap(p1, p2);
    cout << "!" << " " << p1 << " " << p2 << endl;
    //cin.close();
    //cout.close();
    return 0;
}