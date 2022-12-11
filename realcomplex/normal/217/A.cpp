#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	int xc[n],yc[n];
	for(int j= 0 ;j<n;j++){
		cin >> xc[j] >> yc[j];
	}	
	bool vis[n];
    for(int i = 0;i<n;i++)vis[i]=false;
	int ans = -1;
	for(int j = 0;j<n;j++){
		if(!vis[j]){
			ans++;
			vis[j] = true;
			queue<int>visit;
			visit.push(j);
			while(!visit.empty()){
				int lx = xc[visit.front()],ly = yc[visit.front()];visit.pop();
				for(int x = 0;x<n;x++){
					if(xc[x]==lx||yc[x]==ly)
						if(!vis[x]){
							vis[x] = true;
							visit.push(x);
						}
				}
			}
		}
	}
	cout << ans;
	return 0;
}