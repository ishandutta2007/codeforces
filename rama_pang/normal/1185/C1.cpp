#include <bits/stdc++.h>
using namespace std;

int n,M;
int tim,t[1000000];
int main (){
	cin >> n >> M;
	tim=0;
	for (int i = 0; i <n; i++){
		cin >> t[i];
		//time+=t[i];
		
	}
	int failed=0;
	priority_queue<int> pq,temp;
	for (int i = 0; i <n; i++){
		tim+=t[i];
		int save=tim;
		temp=pq;
		failed=0;
		while (save>M){
			failed++;
			save-=temp.top();
			temp.pop();
		}
		cout << failed ;
		if (i<n-1){
			cout << " ";
		}
		
		pq.push(t[i]);
	}
	cout << endl;
}