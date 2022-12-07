#include <bits/stdc++.h>
typedef long long int ll;
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define pair pair<int,int>
#define F first
#define S second
#define mem(x) memset(x,0,sizeof(x))

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    int n = s.length();
    for(int i=0;i<n-2;i++)
    {
      int k[3];
      k[0] = (int) s[i];
      k[1] = (int) s[i+1];
      k[2] = (int) s[i+2];
      sort(k,k+3);
      if((k[0]==((int)'A')) && (k[1]==((int)'B')) && (k[2]==((int)'C')))
      {
         cout<<"Yes"<<endl;
         return 0;
      }

    }
    cout<<"No"<<endl;
    return 0;
}