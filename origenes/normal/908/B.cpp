#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int dx[]={1, -1, 0, 0};
const int dy[]={0, 0, -1, 1};
int c[]={0, 2, 1, 3};
int n, m, sx, sy, ex, ey;
string s[105], op;
bool tmpc(int x, int y){
	if(x<0||x>=n) return false;
	if(y<0||y>=m) return false;
	if(s[x].at(y)=='#') return false;
	return true;
}
bool check(){
	int x=sx, y=sy;
	for(char i:op){
		int dir=c[i-'0'];
		x+=dx[dir];
		y+=dy[dir];
		if(!tmpc(x, y)) return false;
		if(x==ex&&y==ey) return true;
	}
	return false;
}
int main(){
	cin>>n>>m;
	for(int i=0; i<n; i++){
		cin>>s[i];
		for(int j=0; j<s[i].size(); j++){
			if(s[i].at(j)=='S'){
				sx=i;
				sy=j;
			}
			if(s[i].at(j)=='E'){
				ex=i;
				ey=j;
			}
		}
	}
	cin>>op;
	int cnt=0;
	for(c[0]=0; c[0]<4; c[0]++){
		for(c[1]=0; c[1]<4; c[1]++){
			if(c[1]==c[0]) continue;
			for(c[2]=0; c[2]<4; c[2]++){
				if(c[2]==c[1]||c[2]==c[0]) continue;
				for(c[3]=0; c[3]<4; c[3]++){
					if(c[3]==c[2]||c[3]==c[1]||c[3]==c[0]) continue;
					if(check()) cnt++;
				}
			}
		}
	}
	cout<<cnt<<endl;
	return 0;
}