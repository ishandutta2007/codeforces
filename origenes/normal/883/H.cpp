#include <cstdio>
#include <map>
#include <cmath>
#include <queue>
using namespace std;
int n;
char s[412345], t[412345];
map<char, int> cnt;
priority_queue<int> q;
queue<char> odd;
int main(){
	scanf("%d\n%s", &n, s);
	int upp=sqrt(n)+0.5;
	for(int i=1; i<=upp; i++){
		if(n%i==0){
			q.push(i);
			q.push(n/i);
		}
	}
	for(int i=0; i<n; i++)
		cnt[s[i]]++;
	int tot=0;
	for(auto it=cnt.begin(); it!=cnt.end(); it++){
		if((*it).second&1){
			tot++;
			(*it).second--;
			odd.push((*it).first);
		}
	}
	while(!q.empty()){
		int len=q.top();
		q.pop();
		int segs=n/len;
		if(segs<tot||((!(len&1))&&len!=n)) continue;
		printf("%d\n", segs);
		if(len==1){
			for(int i=0; i<n; i++)
				printf("%c ", s[i]);
			return 0;
		}
		auto it=cnt.begin();
		if(len&1){
			for(int cur=0; cur<segs; cur++){
				for(int i=0; i<len>>1; i++){
					while((*it).second==0) it++;
					(*it).second-=2;
					t[i]=(*it).first;
				}
				t[len>>1]='\0';
				printf("%s", t);
				if(!odd.empty()){
					printf("%c", odd.front());
					odd.pop();
				}else{
					while((*it).second==0) it++;
					(*it).second-=2;
					printf("%c", (*it).first);
					odd.push((*it).first);
				}
				for(int i=(len>>1)-1; i>=0; i--)
					printf("%c", t[i]);
				putchar(' ');
			}
		}else{
			for(int cur=0; cur<segs; cur++){
				for(int i=0; i<len>>1; i++){
					while((*it).second==0) it++;
					(*it).second-=2;
					t[i]=(*it).first;
				}
				t[len>>1]='\0';
				printf("%s", t);
				for(int i=(len>>1)-1; i>=0; i--)
					printf("%c", t[i]);
				putchar(' ');
			}
		}
		puts("");
		return 0;
	}
}