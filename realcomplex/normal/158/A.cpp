#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int n;
	cin >> n;
	int k;
	cin >> k;
	vector<int>point;
	int pt;
	for(int i = 0;i<n;i++){
	    cin >> pt;
	    if(pt > 0){
	        point.push_back(pt);
	    }
	}
	sort(point.begin(),point.end());
	int pos[point.size()];
	int poso = 1;
	for(int i = point.size() - 1;i>=0;i--){
	    if(i < point.size() - 1){
	        if(point[i] == point[i + 1]){
	            pos[i] = pos[i + 1];
	        }
	        else{
	            pos[i] = poso;
	        }
	    }
	    else{
	        pos[i] = poso;
	    }
	    poso++;
	}
	int next = 0;
	for(int i = 0;i<point.size();i++){
	    if(pos[i] <= k){
	        next++;
	    }
	}
	cout << next;
	return 0;
}