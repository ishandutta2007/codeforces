#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int n,m,cur,pos = 0;
vector <int> q;
vector <int> sol;
int solu = 0;
int toy = 1;

int main(){
	scanf("%d %d",&n,&m);
	for(int i = 0;i<n;i++){
		scanf("%d",&cur);
		q.push_back(cur);
	}
	sort(q.begin(),q.end());
	while(m>0){
		if(m-toy<0) break;
		if(pos>n){
			m-=toy;
			sol.push_back(toy);
			toy++;
			continue;
		}
		if(q[pos]==toy){
			toy++;
			pos++;
			continue;
		}
		m-=toy;
		sol.push_back(toy);
		solu++;
		toy++;

	}
	printf("%d\n",solu);
	for(int i = 0;i<solu;i++) {
		printf("%d ",sol[i]);
	}
	printf("\n");


}