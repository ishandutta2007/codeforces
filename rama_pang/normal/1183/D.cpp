#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define db(x) cout << ">>>>>>>>>>>>>" << #x << " "<< x << endl
#define IOS ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main (){
	IOS;
	//ll q,k,n,a,b;
	int q;
	cin>>q;
	while (q--){
		int n;
		cin>>n;
		vector<int>arr;
		map<int,int> mp;
		for (int i = 0; i <n; i++){
			int a;
			cin>>a;
			if(mp[a]==0){
				arr.push_back(a);
			
			}
			mp[a]++;
		}
		priority_queue<int> pq;
		for (int i = 0; i <arr.size(); i++){
			pq.push(mp[arr[i]]);
			//cout << mp[arr[i]] << endl;
		}
		//sort(cnt.begin(),cnt.end(), greater<int>());
		//priority_queue<int> pq;
		int maks=0, total=0;
		while (!pq.empty()){
			if (pq.top()<=0){
				break;
			}
			while (maks==pq.top()){
				int k=pq.top();
				k--;
				pq.pop();
				pq.push(k);
				
			}
			total+= pq.top();
			maks=pq.top();
			pq.pop();
			//cout << maks<<endl;
		}
		cout << total << endl;
		//int loc=0,now=1;
		//while (loc<arr.size()){
			
		//}
	}
	
}