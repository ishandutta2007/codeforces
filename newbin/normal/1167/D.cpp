#include<iostream>
#include<stack>
using namespace std;
const int maxn = 2e5 + 50;
char s[maxn];
int n;
int dep[maxn];
stack<int> q;
int main(){
	cin>>n;
	scanf("%s",s);
	dep[0] = 1;q.push(0);
	for(int i = 1;i < n;++i){
		if(s[i] == ')'){
			dep[i] = dep[q.top()];q.pop();
		}
		else{
			if(q.size())dep[i] = dep[q.top()] + 1;
			else dep[i] = 1;
			q.push(i);
		}
	}
	for(int i = 0;i < n;++i) printf("%d",dep[i]&1);printf("\n");
}