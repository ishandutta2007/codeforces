#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <algorithm>

using std::max;
using std::min;

struct Vector{
	int x,y;
};

int rMin,rMax,lx,ly,delta;

void reset(){
	rMin = 1;
	rMax = 8;
	lx = 1;
	ly = 1;
	delta = 0;
}

Vector toVector(const char* s){
	if(strcmp(s,"Right")==0) return {0,1};
	if(strcmp(s,"Left")==0) return {0,-1};
	if(strcmp(s,"Up")==0) return {-1,0};
	if(strcmp(s,"Down")==0) return {1,0};
	if(strcmp(s,"Down-Right")==0) return {1,1};
	if(strcmp(s,"Down-Left")==0) return {1,-1};
	if(strcmp(s,"Up-Right")==0) return {-1,1};
	if(strcmp(s,"Up-Left")==0) return {-1,-1};
	throw true;
}

void move(int x,int y){
	if(x==lx&&y==ly) return;
	lx = x;
	ly = y;
	printf("%d %d\n",x,y);
	fflush(stdout);
	static char buffer[20];
	scanf("%s",buffer);
	Vector result = toVector(buffer);
	delta += result.x;
	rMin = max(rMin,-delta+1);
	rMax = min(rMax,8-delta);
	assert(rMin<=rMax);
}

void solve(){
	reset();
	for(int i=1;i<=8;i++){
		bool n1 = false;
		for(int j=1;j<=8;j++){
			if(i+delta<1||i+delta>8) break;
			n1 = (j!=1);
			move(i+delta,j);
		}
		if(n1) move(lx,1);
	}
	throw false;
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		try{
			solve();
		}catch(bool win){
			assert(win);
		}
	}
}