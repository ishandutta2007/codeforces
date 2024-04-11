#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
vector < pair < char , int > > ans;
int n;
char type[N][12];
int val[N];
priority_queue < int > pq;
void insert(int x){
	pq.push(-x);
}
int getmin(){
	return -pq.top();
}
int main(){
	scanf("%d" , &n);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%s" , type[i]);
		if(type[i][0] != 'r'){
			scanf("%d" , &val[i]);
		}
	}
	ans.clear();
	while(!pq.empty()){
		pq.pop();
	}
	for(int i = 1 ; i <= n ; ++i){
		if(type[i][0] == 'i'){
			insert(val[i]);
			ans.push_back(make_pair('i' , val[i]));
		}
		else if(type[i][0] == 'g'){
			if(pq.empty()){
				insert(val[i]);
				ans.push_back(make_pair('i' , val[i]));
			}
			if(val[i] > getmin()){
				ans.push_back(make_pair('r' , -1));
				pq.pop();
				--i;
				continue;
			}
			if(val[i] < getmin()){
				ans.push_back(make_pair('i' , val[i]));
				insert(val[i]);
			}
			ans.push_back(make_pair('g' , val[i]));
		}
		else{
			if(pq.empty()){
				pq.push(1);
				ans.push_back({'i' , 1});
			}
			pq.pop();
			ans.push_back(make_pair('r' , -1));
		}
	}
	printf("%d\n" , int(ans.size()));
	for(auto it : ans){
		if(it.first == 'i'){
			printf("insert %d\n" , it.second);
		}
		else if(it.first == 'g'){
			printf("getMin %d\n" , it.second);
		}
		else{
			printf("removeMin\n");
		}
	}
}