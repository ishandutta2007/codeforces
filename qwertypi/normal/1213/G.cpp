#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
int Size[200001];
int Parent[200001];
vector<vector<int>> Nodes(200001);
ll Ans[200001];
 
struct line{
	int v1, v2, cost;
};
 
vector<line> lines(200000); 
int n, m;
ll ans;
 
int cmp(line A, line B){
	return A.cost < B.cost;
}
 
int root(int A){
	while(A != Parent[A]){
		Parent[A] = Parent[Parent[A]];
		A = Parent[A];
	}
	return A;
}
 
void Union(int A, int B){
	int root_A = root(A);
	int root_B = root(B);
	ans += 2LL * Size[root_A] * Size[root_B];
	if(Size[root_A] <= Size[root_B]){
		Nodes[root_B].insert(Nodes[root_B].begin() + Size[root_B], Nodes[root_A].begin(), Nodes[root_A].end());
		Nodes[root_A].resize(0);
		Size[root_B] += Size[root_A];
		Size[root_A] = 0;
		Parent[root_A] = root_B;
	}else{
		Nodes[root_A].insert(Nodes[root_A].begin() + Size[root_A], Nodes[root_B].begin(), Nodes[root_B].end());
		Nodes[root_B].resize(0);
		Size[root_A] += Size[root_B];
		Size[root_B] = 0;
		Parent[root_B] = root_A;
	}
}
 
int main(){
	cin >> n >> m;
	ans = n;
	for(int i=0;i<n-1;i++){
		line v;
		cin >> v.v1 >> v.v2 >> v.cost;
		lines[i] = v;
	}
	sort(lines.begin(), lines.end(), cmp);
	for(int i=1;i<=n;i++){
		Parent[i] = i;
		Size[i] = 1;
		Nodes[i].push_back(i);
	}
	int curPos = 0;
	for(int C = 1; C <= 200000; C++){
		while(curPos < lines.size()){
			if(lines[curPos].cost > C){
				break;
			}else{
				line K = lines[curPos++];
				Union(K.v1, K.v2);
			}
		}
		Ans[C] = ans;
	}
	for(int i=0;i<m;i++){
		int v;
		cin >> v;
		cout << (Ans[v] - n) / 2 << ' ' ;
	}
}