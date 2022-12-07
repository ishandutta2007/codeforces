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

    int n,q;
    cin>>n>>q;
    int arr[n];
    
    int counter_q = 0;
    ForA1(n)
    {
        cin>>arr[i];
        if(arr[i]==q)
        {
            counter_q++;
        }
    }
    if(n==1)
    {
        if(arr[0]==0||arr[0]==q)
            cout<<"YES"<<endl<<q<<endl;
        else
            cout<<"NO"<<endl;
        return 0;
    }
    if(counter_q==0)
    {
        int flag = 0;
        ForA1(n)
        {
            if(arr[i]==0)
            {
                flag = 1;
                arr[i]=q;
                break;
            }
        }
        if(flag==0)
        {
            cout<<"NO"<<endl;
            return 0;
        }
    }
    for(int i=1;i<n-1;i++)
    {
        if(arr[i]==0)
            arr[i] = max(arr[i+1],arr[i-1]);
    }
    for(int i=n-2;i>0;i--)
    {
        if(arr[i]==0)
            arr[i] = max(arr[i+1],arr[i-1]);
    }
    if(arr[0]==0)
        arr[0]= arr[1];
    if(arr[n-1]==0)
        arr[n-1] = arr[n-2];
    map<int,int> corr;
    stack <int> quiz;
    quiz.push(1);
    for(int i=0;i<n;i++)
    {
        if(corr[arr[i]]!=0)
        {
            cout<<"NO"<<endl;
            return 0;
        }
        while(quiz.top()>arr[i])
        {
            corr[quiz.top()]++;
            quiz.pop();
        }
        quiz.push(arr[i]);
    }
    cout<<"YES"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}