#include <bits/stdc++.h>

using namespace std;

int main() {
	
	int n;
	cin >> n;
	bool elementi[n];
	vector<int>pos0;
	int sk;
	int allP[n];
	for(int i = 0;i<n;i++){
		cin >> sk;
		if(sk == 0){
			elementi[i] = false;
			pos0.push_back(i);
		}
		else{
			elementi[i] = true;
		}
	}
	int start,end;
	for(int i = 0;i<=pos0[0];i++){
		allP[i] = pos0[0] - i;
	}
	start = pos0[0];
	end = pos0[pos0.size() - 1];
	for(int i = pos0[pos0.size() - 1];i<n;i++){
		allP[i] = i - pos0[pos0.size() - 1];
	}
	int elements = 1;
	for(int i = start + 1;i < end;i++){
		if(i > pos0[elements]){
			elements++;
		}
		allP[i] = min(i - pos0[elements - 1],pos0[elements] - i);
	}
	for(int i = 0;i<n;i++){
		cout << allP[i] << " ";
	}
	return 0;
}