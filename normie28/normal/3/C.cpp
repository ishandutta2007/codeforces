// Credit to robs77 for this template
/***********HEADER***************/
#include <iostream>
#include <bitset>
#include <deque>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <algorithm>
#include <list>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <set>
#include <queue>
#include <map>
/***********MACROS***************/
#define int long long 
#define ll  long long 
#define fri(l,k) for (i=l;i<=k;i++)
#define frj(l,k) for (j=l;j>=k;j--)
#define fij(a,b,l,k) for(i=a;i<=b;i++) for(j=l;j<=k;j++)
#define all(x) x.begin(),x.end()
#define allr(x) x.rbegin(),x.rend()
#define endl "\n"
#define pb push_back
#define _1 first
#define _2 second
#define mxsz 1000000007
#define mxval 1e9 + 7
#define grt [](auto x,auto y){return x>y;}
#define pii pair<int,int>
/*********VARIABLE****************/
using namespace std;
char grid[3][3];
int contx=0,cont0=0,winsx=0,winsy=0;
 
/*********FUNCTIONS**************/
void readGrid(){
	for(int i=0;i<3;i++)
		cin>>grid[i];
 
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(grid[i][j]=='X') contx++;
			else if(grid[i][j]=='0') cont0++;
		}
	}
 
}
void solve(){
	if(contx!=cont0 && (contx-1)!=cont0){
		cout<<"illegal";
		return;
	}
 

	for(int i=0;i<3;i++){
		bool winR=true,winC=true;	
		char pwR=grid[i][0],pwC=grid[0][i];
		if(pwR=='.') winR=false;
		if(pwC=='.') winC=false;
		for(int j=1;j<3;j++){
			if(pwR!=grid[i][j]) winR=false;
			if(pwC!=grid[j][i]) winC=false;
		}
		if(winR){
			if(pwR=='X') winsx++;
			else winsy++;
		}
		if(winC){
			if(pwC=='X') winsx++;
			else winsy++;
		}
	}
 

	bool win1=true,win2=true;
	char pw1=grid[0][0],pw2=grid[0][2];
	if(pw1=='.') win1=false;
	if(pw2=='.') win2=false;
	for(int i=1;i<3;i++){
		if(pw1!=grid[i][i]) win1=false;
		if(pw2!=grid[i][2-i]) win2=false;
	}
	if(win1){
		if(pw1=='X') winsx++;
		else winsy++;
	}
	if(win2){
		if(pw2=='X') winsx++;
		else winsy++;
	}
	if(winsx==0 && winsy==0){
		if(contx+cont0==9) cout<<"draw";
		else if(contx==cont0) cout<<"first";
		else cout<<"second";
	}
	else if((winsx && winsy==0) && contx-1==cont0)
		cout<<"the first player won";
	
	else if((winsy && winsx==0) && contx==cont0)
		cout<<"the second player won";
	
	else cout<<"illegal";
}
 
/***********MAIN**************/

signed main(){
 
	readGrid();
	solve();
 
	return 0;
}

//.........