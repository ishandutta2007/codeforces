#include<bits/stdc++.h>
#define ll long long int
#define ul unsigned long long int
#define pb push_back
#define mp make_pair
#define ii pair<int,int>
#define vi vector<int>
#define iii pair<int,pair<int,int>>
#define INF 1<<30

using namespace std;
ll hash1[2000][2] = {0};
ll hash2[2000][2] = {0};
int m = 1000000007L;
string A[2000], B[200];
ll Hash1(int k, int I, int m) {
	ll seed1=27349841, seed2=45673703;
	if(k==1){
		ll ha=0;
		for(int i=0; i<m; i++){
		    for(int j=0;j<m;j++){
			    ha=(ha*seed1+A[I+i][j])%seed2;
		    }
		}
		return ha;
	}
	else {
		ll ha=0;
		for(int i=0; i<m; i++){
		    for(int j=0;j<m;j++){
			ha=(ha*seed1+B[i][I+j])%seed2;
		    }}
		return ha;
	}
}
ll Hash2(int k, int I, int m) {
	ll seed1=840927469, seed2=1438790207;
	if(k==1){
		ll ha=0;
		for(int i=0; i<m; i++){
		    for(int j=0;j<m;j++){
			    ha=(ha*seed1+A[I+i][j])%seed2;
		    }
		}
		return ha;
	}
	else {
		ll ha=0;
		for(int i=0; i<m; i++){
		    for(int j=0;j<m;j++){
			ha=(ha*seed1+B[i][I+j])%seed2;
		    }}
		return ha;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,m;
	cin>>n>>m;
	for (int i = 0; i < n; ++i)
	{
		cin>>A[i];
	}
	for (int i = 0; i < m; ++i)
	{
		cin>>B[i];
	}
	for(int i=0; i<=(n-m); i++){
		hash1[i][0] = Hash1(1,i,m);
	}
	for(int i=0; i<=(n-m); i++){
		hash2[i][0] = Hash1(2,i,m);
    }
	int r=-1,c=-1;
	bool b=false;
	for(int i=0;i<=(n-m)&&(!b);i++) {
	    for(int j=0;j<=(n-m)&&(!b);j++) {
	        if(hash1[i][0] == hash2[j][0]){
	            cout<<(i+1)<<" "<<(j+1);
	            b = true;
	        }
	    }
	}
}