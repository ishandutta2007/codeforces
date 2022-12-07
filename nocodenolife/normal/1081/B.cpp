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

#define modder 1000000007
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define pair pair<int,int>
#define F first
#define S second
#define mem(x) memset(x,0,sizeof(x))
#define PI 3.1415926535897932384626433832795l
#define deci(n) cout<<fixed<<setprecision(n);


using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin>>n;
    
    int arr[n];
    int answer[n+1] = {0};
    int divi[n+1] = {0};
    int num;
    ForA1(n)
    {
        cin>>num;
        num = n-num;
        arr[i] = num;
        divi[num]++;
    }
    int cur = 1;
    ForA1(n+1)
    {
        if(divi[i]==0)
            continue;
        answer[i]=cur;
        cur++;
        if(divi[i]%i!=0)
        {
            cout<<"Impossible"<<endl;
            return 0;
        }
    }
    
    cout<<"Possible"<<endl;
    ForA1(n)
    {
        cout<<answer[arr[i]]<<" ";
        divi[arr[i]]--;
        if(divi[arr[i]]!=0 && divi[arr[i]]%arr[i]==0)
        {
            answer[arr[i]]=cur;
            cur++;
        }
    }
    
    
    
    return 0;
}