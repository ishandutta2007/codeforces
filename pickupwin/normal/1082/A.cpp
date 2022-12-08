#include <iostream>

using namespace std;

const int INF=1034567890;

int T;
int N;
int x, y, d;

bool Reach(int a, int b){
	int dis=b-a;
	if(dis<0)	dis=-dis;
	return dis%d==0;
}

int Cnt(int l, int r){
	if(l>r)	swap(l, r);
	int dis=r-l;
	int ret=dis/d;
	if(dis%d)	++ret;
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	
	
	cin >> T;
	
	while(T--){
		cin >> N >> x >> y >> d;
		
		int Ans=INF;
		
		if(Reach(x, y))
			Ans=min(Ans, Cnt(x, y));
		
		if(Reach(1, y))
			Ans=min(Ans, Cnt(x, 1)+Cnt(1, y));
		
		if(Reach(y, N))
			Ans=min(Ans, Cnt(x, N)+Cnt(y, N));
		
		cout << ((Ans>=INF)?-1:Ans) << endl;
		
	}
	
	return 0;
}