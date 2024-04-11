#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;

const int N=2e5+5,L=18,mod=1e9+7;

int add(int a,int b){
    a+=b;
    if(a>=mod)
        a-=mod;
    return a;
}
int mul(int a,int b){
    return ((long long)a*b)%mod;
}

vector<int> pwrs(1,1);
pair<int,int> hsh[N][L];
int up[N][L];
string s;
pair<int,int> mergeHsh(pair<int,int> a,pair<int,int> b){
	return {add(mul(a.f,pwrs[b.s]),b.f),a.s+b.s};
}
pair<int,int> calc(int l,int r){
	pair<int,int> sol={0,0};
	for(int j=L-1;j>=0;j--)
		if(up[l][j]-1<=r){
			sol=mergeHsh(sol,hsh[l][j]),l=up[l][j];
		}
	if(l==r){
		sol=mergeHsh(sol,{0,1});
		l++;
	}
	return sol;
}
int main()
{
	for(int i=0;i<N;i++)
		pwrs.push_back(mul(pwrs.back(),2));
	int n;
	scanf("%i",&n);
	cin >> s;
	s+='0';
	up[n][0]=n;
	for(int i=0;i<n;i++){
		if(s[i]=='0')
			up[i][0]=i+1,hsh[i][0]={1,1};
		else
			if(s[i+1]=='1')
				up[i][0]=i+2,hsh[i][0]={0,0};
			else
				up[i][0]=i+1,hsh[i][0]={0,1};
	}
	for(int j=1;j<L;j++)
		for(int i=0;i<=n;i++)
			hsh[i][j]=mergeHsh(hsh[i][j-1],hsh[up[i][j-1]][j-1]),up[i][j]=up[up[i][j-1]][j-1];
	int q;
	scanf("%i",&q);
	while(q--){
		int a,b,len;
		scanf("%i %i %i",&a,&b,&len);
		a--;b--;
		printf(calc(a,a+len-1)==calc(b,b+len-1)?"YES\n":"NO\n");
	}
	return 0;
}