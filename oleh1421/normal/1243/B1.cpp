#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
#include <cmath>

#define pii pair<int, int>
#define all(a) a.begin(),a.end()
#define y1 erd
#define int long long

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl "\n"

typedef long long ll;

using namespace std;

const int M = 1e9 + 7;

int n;
string s;
string t;
int32_t main()
{
    int tt;
    cin >> tt;
    while (tt--)
    {
        cin >> n >> s >> t;
        vector<int> k;
        for(int i = 0; i < n; i++){
            if(s[i] != t[i])
                k.push_back(i);
        }
        if(k.size() != 2)
            cout << "No";
        else
        {
            int i = k[0];
            int j = k[1];
            swap(s[i], t[j]);
            if(s == t){
                cout << "Yes";
            }
            else
            {
                swap(s[i], t[j]);
                swap(t[i], s[j]);
                if(s == t)
                    cout << "Yes";
                else
                {
                    cout << "No";
                }

            }

        }
        cout << endl;
    }
}