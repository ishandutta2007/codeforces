#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define db(x) cout << ">>>>>>>>>>>>>" << #x << " "<< x << endl
#define IOS ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
struct g{
	int num;
	int f;
	bool operator <(const g &o)const {
		return num<o.num or (num==o.num and f<o.f);
	}
};
int main (){
	IOS;
	//ll q,k,n,a,b;
	int q;
	cin>>q;
	while (q--){
		int n;
		cin>>n;
		vector<int>arr;
		map<int,int> mp,mp2;
		for (int i = 0; i <n; i++){
			int a,b;
			cin>>a>>b;
			if(mp[a]==0){
				arr.push_back(a);
			
			}
			mp[a]++;
			mp2[a]+=b;
			
		}
		priority_queue<g> pq;
		for (int i = 0; i <arr.size(); i++){
			pq.push({mp[arr[i]], mp2[arr[i]]});
			//cout << mp[arr[i]] << endl;
		}
		//sort(cnt.begin(),cnt.end(), greater<int>());
		//priority_queue<int> pq;
		int maks=0, total=0, totalf=0;
		while (!pq.empty()){
			if (pq.top().num<=0){
				break;
			}
			while (maks==pq.top().num){
				g k=pq.top();
				k.num--;
				if(k.num<k.f) k.f--;
				pq.pop();
				pq.push(k);
				
			}
			total+= pq.top().num;
			maks=pq.top().num;
			totalf+=pq.top().f;
			
			pq.pop();
			
			//cout << maks<<endl;
		}
		cout << total << " "<<totalf<<endl;
		//int loc=0,now=1;
		//while (loc<arr.size()){
			
		//}
	}
	
}