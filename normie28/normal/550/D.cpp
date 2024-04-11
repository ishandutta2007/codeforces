#include<bits/stdc++.h>
using namespace std;
vector<int> edge[100005];
int pos = 2;
vector<int> ulti;
int k;
void rec(int node, int depth)
{
	vector<int> vt;
	for(int i = 0; i<k-1; i++){
		edge[node].push_back(pos);
		vt.push_back(pos++);
	}
	if(depth==1){
		ulti.push_back(pos++);
		for(int i = 0; i<k-1; i++){
			edge[pos-1].push_back(vt[i]);
			for(int j = i+1; j<k-1; j++)
					edge[vt[i]].push_back(vt[j]);
		}
		return;
	}
	for(int i = 0; i<k-1; i++)
		rec(vt[i], depth+1);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> k;
    if(k%2==0) {cout << "NO" << endl; return 0;}
    rec(1, 0);
    for(int i = 1; i<k-1; i+=2)
    	edge[ulti[i-1]].push_back(ulti[i]);
    ulti.clear();
    edge[1].push_back(pos);
    rec(pos++, 0);
    for(int i = 1; i<k-1; i+=2)
    	edge[ulti[i-1]].push_back(ulti[i]);
    cout << "YES\n" ;
    int e = 0;
    for(int i = 1; i<pos; i++) e += edge[i].size();
    cout << pos-1 << " " << e <<"\n";
    for(int i = 1; i<pos ; i++){
    	for(int v : edge[i])
    		cout << i << " " << v << "\n";
    }
}