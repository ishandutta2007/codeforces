#include<bits/stdc++.h>
#define int long long
using namespace std;

int u,v;

signed main()
{
	cin>>u>>v;
	if (u>v||(v-u)&1){puts("-1");return 0;}
	if (u==0&&v==0){cout<<0;return 0;}
	if (u==v){cout<<1<<endl<<u;return 0;}
	if ((((v-u)/2)&u)==0)cout<<2<<endl<<(v-u)/2<<' '<<(v-u)/2+u;
	else cout<<3<<endl<<u<<' '<<(v-u)/2<<' '<<(v-u)/2;
	return 0;
}