#include <bits/stdc++.h>

typedef unsigned long long int ull;
typedef long double ldb;
typedef long long int ll;

#define ForA1(n)  for (ll i=0; i<n; i++)
#define ForA2(n)  for (ll j=0; j<n; j++)
#define ForA3(n)  for (ll k=0; k<n; k++)
#define ForN1(n)  for (ll i=1; i<=n; i++)
#define ForN2(n)  for (ll j=1; j<=n; j++)
#define ForN3(n)  for (ll k=1; k<=n; k++)

#define mod 1000000007
#define pb push_back
#define mp make_pair
#define vll vector<ll>
#define F first
#define S second
#define debug(x)    cerr << #x << " = " << x << endl;
#define mem(x) memset(x,0,sizeof(x))
#define PI 3.1415926535897932384626433832795l
#define deci(n) cout<<fixed<<setprecision(n);


using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,b,a;
    cin>>n;
    std::vector<pair<int,int> > values;
    ll suma=0;
    ForN1(n)
    {
    	cin>>b;
    	suma+=b;
    	values.push_back({b,i});
    } 
    sort(values.begin(),values.end());

    std::vector<int> final;
    ForN1(n)
    {
    	cin>>b;
    	suma-=b;
    	final.push_back(b);
    } 
    if(suma!=0)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    sort(final.begin(),final.end());

    ll sum =0;
    vector<pair<pair<int,int>,int>> sol;
    pair<int,int> init;
    int fina,te;
    stack<pair<int,int> > st;
    ForA1(n)
    {
        init = values[i];
        fina = final[i];
        sum += fina-init.first;
        if(sum<0)
        {
            cout<<"NO"<<endl;
            return 0;
        }
        if(init.first==fina)
            continue;
        if(init.first>fina)
        {
            fina = init.first - fina;
            te = init.second;
            while(fina>0)
            {
                init = st.top();
                st.pop();
                if(init.first>fina)
                {
                    init.first-=fina;
                    sol.push_back({{init.second,te},fina});
                    fina = 0;
                    st.push(init);
                }
                else
                {
                    sol.push_back({{init.second,te},init.first});
                    fina-=init.first;
                }
                
            }
        }
        else
        {
            st.push({fina-init.first,init.second});
        }
    }
    
    
    cout<<"YES"<<endl;
    cout<<sol.size()<<endl;
    ForA1(sol.size())
    {
    	cout<<sol[i].first.first<<" "<<sol[i].first.second<<" "<<sol[i].second<<endl;
    }

    return 0;
}