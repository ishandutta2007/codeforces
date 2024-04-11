#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll gcd(ll a,ll b)
{
    while (b>0)
    {
        ll tmp = a;
        a = b;
        b = tmp%a;
    }
    return a;
}       


int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);

    int n;
    cin >> n;
    for (int i=0;i<n;++i)
    {
        ll p,q,b;
        cin >> p >> q >> b;
        if (p==0)
        {
            cout << "Finite" << endl;
            continue;
        }

        ll g = gcd(p,q);
        q/=g;

        while(b!=1)
        {
            b = gcd(b,q);
            if (b!=1)
            {
                while (q%b==0)
                    q/=b;
            }
        }
        if (q==1)
            cout << "Finite" << endl;
        else
            cout << "Infinite" << endl;
    }
}