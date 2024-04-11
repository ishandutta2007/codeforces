#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int c[102][102];
int n;

pair<int, int> next(pair<int, int> x)
{
    x.second += 2;
    if(x.second > n)
        return make_pair(x.first + 1, 1 + x.second%2);
    else return x;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    int odd = (n*n+1)/2, even = (n*n)/2;
    int o = 0, e = 0;
    pair<int, int> O = {1, 1}, E = {1, 2};
    for(int i=1;i<=n*n;i++)
    {
        int k; cin >> k;
        if(o == odd)
        {
            int t;
            if(k == 2) t = 3;
            else t = 2;
            cout << t << " " << E.first << " " << E.second << endl;
            E = next(E);

            continue;
        }

        if(e == even)
        {
            int t;
            if(k == 1) t = 3;
            else t = 1;
            cout << t << " " << O.first << " " << O.second << endl;
            O = next(O);

            continue;
        }
        if(k == 1)
        {
            cout << "2 " << E.first << " " << E.second << endl;
            E = next(E);
            e++;
            continue;
        }
        else
        {
            cout << "1 " << O.first << " " << O.second << endl;
            O = next(O);
            o++;
        }
    }
}