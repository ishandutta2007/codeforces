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
#define mem(x) memset(x,-1,sizeof(x))
#define PI 3.1415926535897932384626433832795l
#define deci(n) cout<<fixed<<setprecision(n);


using namespace std;

ll getmove(ll dest, ll cur)
{
    if(cur>dest)
        return -1;
    if(cur<dest)
        return 1;
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll king_x, king_y;
    cin>>king_x>>king_y;
    pair<ll,ll> rooks[666];
    ll move_x, move_y;
    ll board[1000][1000] = {{0}};
    
    
    ll x,y,k;
    ForA1(666)
    {
        cin>>x>>y;
        rooks[i] = make_pair(x,y);
        board[x][y] = 1;
    }
        
    while(king_x!=500 || king_y!=500)
    {
        move_x = getmove(500,king_x);
        move_y = getmove(500,king_y);
        
        if(board[king_x+move_x][king_y+move_y]==0)
        {
            king_x+=move_x;
            king_y+=move_y;
        }
        else
        {
            king_x+=move_x;
        }
        
        cout<<king_x<<" "<<king_y<<endl;
        
        cin>>k>>x>>y;
        if(k<=0)
        {
            return 0;
        }
        k--;
        board[rooks[k].first][rooks[k].second]=0;
        rooks[k] = make_pair(x,y);
        board[rooks[k].first][rooks[k].second]=1;
    }
    
    pair<ll,ll> possi[] = {make_pair(1,1),make_pair(1,999),make_pair(999,1),make_pair(999,999)};
    ll dest_x,dest_y;
    ll cur=-1;
    ll counter[4] = {666,666,666,666};
    ForA1(666)
    {
        if(rooks[i].first>500 && rooks[i].second>500)
            counter[0]--;
        else if(rooks[i].first>500 && rooks[i].second<500)
            counter[1]--;
        else if(rooks[i].first<500 && rooks[i].second>500)
            counter[2]--;
        else
            counter[3]--;
    }
    ForA1(4)
    {
        if(counter[i]>cur)
        {
            cur = counter[i];
            dest_x = possi[i].first;
            dest_y = possi[i].second;
        }
    }
    
    while(king_x!=dest_x || king_y!=dest_y)
    {
        move_x = getmove(dest_x,king_x);
        move_y = getmove(dest_y,king_y);
        
        if(board[king_x+move_x][king_y+move_y]==0)
        {
            king_x+=move_x;
            king_y+=move_y;
        }
        else
        {
            king_x+=move_x;
        }
        
        cout<<king_x<<" "<<king_y<<endl;
        
        cin>>k>>x>>y;
        if(k<=0)
        {
            return 0;
        }
        k--;
        board[rooks[k].first][rooks[k].second]=0;
        rooks[k] = make_pair(x,y);
        board[rooks[k].first][rooks[k].second]=1;
    }
    
    
    return 0;
}