#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
int fx1[4]={0,0,-1,1},fx2[4]={-1,1,0,0};
int main(){
	int n,m,aa[4]={3,2,1,0},s1,s2,t1,t2;
	string s;
	char a[52][52];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
			if(a[i][j]=='S'){
				s1=i;s2=j;
			}
			if(a[i][j]=='E'){
				t1=i;t2=j;
			}
		}
	}
	cin>>s;
	int ans=0,x,y;
	do{
		x=s1;y=s2;
		for(int i=0;i<s.size();i++){
			x+=fx1[aa[s[i]-'0']];y+=fx2[aa[s[i]-'0']];
			if(x<1||y<1||x>n||y>m)break;
			if(a[x][y]=='#')break;
			if(x==t1&&y==t2){
				ans++;break;
			}
		}
	}while(prev_permutation(aa,aa+4));
	cout<<ans;
	return 0;
}