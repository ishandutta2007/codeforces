#include <bits/stdc++.h>

typedef unsigned long long int ull;
typedef long double ldb;
typedef long long int ll;

#define ForA1(n)  for (ll i=0; i<n; i++)
#define ForA2(n)  for (ll j=0; j<n; j++)
#define ForA3(n)  for (ll k=0; k<n; k++)

#define ForN2(n)  for (ll j=1; j<=n; j++)
#define ForN3(n)  for (ll k=1; k<=n; k++)

//#define ForN1(n)  for(ll i=1; i<n; i++)

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


struct Pa
{
   string name;
   int len;
};
typedef struct Pa pairs;

bool waytosort(pairs a, pairs b)
{
   return a.len < b.len;
}

// Returns true if s2 is substring of s1
int isSubstring(string s1, string s2)
{
    int M = s1.length();
    int N = s2.length();

    /* A loop to slide pat[] one by one */
    for (int i = 0; i <= N - M; i++) {
        int j;

        /* For current index i, check for pattern match */
        for (j = 0; j < M; j++)
            if (s2[i + j] != s1[j])
                break;

        if (j == M)
            return i;
    }

    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    pairs arr[n];
    ForA1(n)
    {
      cin>>arr[i].name;
      arr[i].len = arr[i].name.length();
    }

    sort(arr,arr+n,waytosort);

    for(ll i=1; i<n; i++)
    {
      if (isSubstring(arr[i-1].name,arr[i].name) == -1)
      {
            cout<<"NO"<<endl;
            return 0;
      }
    }
    cout<<"YES"<<endl;
    ForA1(n)
    {
      cout<<arr[i].name<<endl;
    }

    return 0;
}