#include <bits/stdc++.h>
typedef long long int ll;
#define finc(i,a,b) for(ll i = a; i<b;i++)
#define fdec(i,a,b) for(ll i = a; i>=b;i--)
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define pair pair<int,int>
#define F first
#define S second
#define mem(x) memset(x,0,sizeof(x))

using namespace std;
ll ans;
ll n;

void solve_right(ll * a, ll row, ll column, ll tim, ll counter, ll* sums, ll* adder)
{
    // for(ll i=column;i<n;i++)
    // {
    //     counter+= tim * a[row*n +i];
    //     tim++;
    // }
    // row = (row+1)%2;
    // for(ll i=n-1;i>=column;i--)
    // {
    //     counter+= tim * a[row*n + i];
    //     tim++;
    // }
    counter+= adder[row*n+column];
    counter+= tim*sums[column];
    if(counter>ans)
        ans = counter;
    return;
}

void solve(ll * a, ll row, ll column, ll tim, ll counter, ll* sums, ll* adder)
{
    if(column == n-1)
    {
        counter+= a[row*n+column]*tim;
        tim++;
        row = ((row+1)%2);
        counter+= a[row*n+column]*tim;
        tim++;
        if(counter>ans)
            ans = counter;
        return;
    }
    solve_right(a,row, column, tim, counter,sums,adder);
    counter+= a[row*n+ column]*tim;
    tim++;
    row = ((row+1)%2);
    counter+= a[row*n+column]*tim;
    tim++;
    solve(a,row,column+1,tim,counter,sums,adder);
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>n;
    ans =0;
    ll a[2*n];
    ll sums[n];
    ll adder[2*n];
    finc(i,0,n)
    {
        cin>>a[i];
    }
    finc(i,0,n)
    {
        cin>>a[n+i];
        sums[i] = a[i]+a[n+i];
    }
    fdec(i,n-2,0)
    {
        sums[i] += sums[i+1];
    }

    adder[n-1] = a[2*n-1];
    adder[2*n-1] = a[n-1];
    fdec(i,n-2,0)
    {
        adder[i] = adder[i+1] + sums[i+1];
        ll dif = n-i;
        adder[i] += (2*dif-1) * a[i+n];
    }
    fdec(i,2*n-2,n)
    {
        adder[i] = adder[i+1] + sums[i+1-n];
        ll dif = 2*n-i;
        adder[i] += (2*dif-1) * a[i-n];
    }

    solve(a,0,0,0,0 , sums,adder);
    cout<<ans<<endl;
    return 0;
}