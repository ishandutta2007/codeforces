#include<bits/stdc++.h>
#define LL long long
using namespace std;
int n,s1,s2,a[1000010],b[1000010];
set<int> s;
int check(int x){
	s.clear();
	if (abs(a[0]-s1)<=x) s.insert(s1);
	if (abs(a[0]-s2)<=x) s.insert(s2);
	for (int i=1;i<n;i++){
		if (s.empty()) return 0;
		set<int>::iterator it=s.begin();
		while (it!=s.end()&&abs(*it-a[i])>x){
			int tmp=*it;
			it++;
			s.erase(tmp);
		}
		set<int>::reverse_iterator it1=s.rbegin();
		int cnt=0;
		while (it1!=s.rend()&&abs(*it1-a[i])>x){
			b[cnt++]=*it1;
			it1++;
		}
		for (int j=0;j<cnt;j++) s.erase(b[j]);
		if (abs(a[i-1]-a[i])<=x) s.insert(a[i-1]);
	}
	if (s.empty()) return 0;
	return 1;
}
int main() {
	scanf("%d%d%d",&n,&s1,&s2);
	for (int i=0;i<n;i++) scanf("%d",&a[i]);
	int l=abs(s2-s1),r=1000000000,mid;
	while (l<r){
		mid=(l+r)/2;
		if (check(mid)) r=mid;
		else l=mid+1;
	}
	printf("%d\n",r);
}