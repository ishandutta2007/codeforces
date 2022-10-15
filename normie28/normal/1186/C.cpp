#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define sp std::fixed<<std::setprecision
#define MOD 1000000007
#define MAX 1e18
#define N 1000005
using namespace std;
 
ll xa[1000005] , xb[1000005];
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll cnt = 0 , ans = 0;
    string a , b;
    cin >> a >> b;
	a.push_back('0');
	int bz = 0, az = 0;
	for( int i = 0 ; i < b.size() ; i++ )
    {
        bz += b[i] == '0';
        az += a[i] == '0';
    }
	for( int i = b.size() ; i < a.size() ; i++ )
    {
		if( abs( az - bz ) % 2 == 0 )
            ans++;
		az += a[i] == '0';
		az -= a[i - b.size()] == '0';
	}
	cout << ans << endl;
}