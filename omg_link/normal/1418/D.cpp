#include <stdio.h>
#include <set>
typedef std::set<int>::iterator IT;

int n,q;

std::set<int> p;
std::multiset<int> m;

int glst(IT it){
	if(it != p.begin())
		return *(--it);
	return -1;
}

int gnxt(IT it){
	++it;
	if(it == p.end())
		return -1;
	return *it;
}

void addM(int x){
	m.insert(x);
}

void removeM(int x){
	m.erase(m.find(x));
}

void addP(int x){
	p.insert(x);
	IT it = p.find(x);
	int lst=glst(it),nxt=gnxt(it);
	if(lst!=-1&&nxt!=-1)
		removeM(nxt-lst);
	if(lst!=-1)
		addM(x-lst);
	if(nxt!=-1)
		addM(nxt-x);
}

void removeP(int x){
	IT it = p.find(x);
	int lst=glst(it),nxt=gnxt(it);
	if(lst!=-1&&nxt!=-1)
		addM(nxt-lst);
	if(lst!=-1)
		removeM(x-lst);
	if(nxt!=-1)
		removeM(nxt-x);
	p.erase(x);
}

int ans(){
	if(p.begin()==p.end()) return 0;
	int tans = (*(--p.end()))-(*p.begin());
	if(m.begin()!=m.end())
		tans -= (*(--m.end()));
	return tans;
}

int main(){
	scanf("%d%d",&n,&q);
	for(int i=1,a;i<=n;i++){
		scanf("%d",&a);
		addP(a);
	}
	printf("%d\n",ans());
	for(int i=1,opt,x;i<=q;i++){
		scanf("%d%d",&opt,&x);
		if(opt==0) removeP(x);
		if(opt==1) addP(x);
		printf("%d\n",ans());
	}
}