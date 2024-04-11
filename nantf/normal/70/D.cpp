#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline int read(){
	char ch=getchar();int x=0,f=0;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
struct point{
	int x,y;
	point(int x_=0,int y_=0):x(x_),y(y_){}
	point(map<int,int>::iterator it):x(it->first),y(it->second){}
	bool operator<(const point &p)const{
		if(x!=p.x) return x<p.x;
		return y<p.y;
	}
};
int q;
map<int,int> uphull,downhull;
typedef point vec;
inline vec getvec(int x1,int y1,int x2,int y2){
	return vec(x2-x1,y2-y1);
} 
inline vec getvec(point p1,point p2){
	return getvec(p1.x,p1.y,p2.x,p2.y);
}
inline ll cross(vec v1,vec v2){
	return 1ll*v1.x*v2.y-1ll*v2.x*v1.y;
}
inline ll area(point p1,point p2,point p3){
	return cross(getvec(p1,p2),getvec(p1,p3));
}
bool check_up(int x,int y){
	point p(x,y);
	auto it1=uphull.lower_bound(x);
	if(it1==uphull.end()) return false;
	if(it1->first==x) return y<=it1->second;
	if(it1==uphull.begin()) return false;
	auto it2=it1;it2--;
	return area(it2,it1,p)<=0;
}
bool check_down(int x,int y){
	point p(x,y);
	auto it1=downhull.lower_bound(x);
	if(it1==downhull.end()) return false;
	if(x==it1->first) return y>=it1->second;
	if(it1==downhull.begin()) return false;
	auto it2=it1;it2--;
	return area(it2,it1,p)>=0;
}
bool check(int x,int y){
	return check_up(x,y)&&check_down(x,y);
}
bool remove_up(map<int,int>::iterator it1){
	if(it1==uphull.begin()) return false;
	auto it2=it1,it3=it1;
	it2--;it3++;
	if(it3==uphull.end()) return false;
	if(area(it2,it3,it1)<=0) return uphull.erase(it1),true;
	return false;
}
bool remove_down(map<int,int>::iterator it1){
	if(it1==downhull.begin()) return false;
	auto it2=it1,it3=it1;
	it2--;it3++;
	if(it3==downhull.end()) return false;
	if(area(it2,it3,it1)>=0) return downhull.erase(it1),true;
	return false;
}
void insert_up(int x,int y){
	if(check_up(x,y)) return;
	uphull[x]=y;
	auto it1=uphull.find(x),it2=it1;
	if(it1!=uphull.begin()){
		for(it2--;it2!=uphull.begin();it2--)
			if(!remove_up(it2++)) break;
	}
	it2=it1;
	for(it2++;it2!=uphull.end();it2++) 
		if(!remove_up(it2--)) break;
}
void insert_down(int x,int y){
	if(check_down(x,y)) return;
	downhull[x]=y;
	auto it1=downhull.find(x),it2=it1;
	if(it1!=downhull.begin()){
		for(it2--;it2!=downhull.begin();it2--)
			if(!remove_down(it2++)) break;
	}
	it2=it1;
	for(it2++;it2!=downhull.end();it2++)
		if(!remove_down(it2--)) break;
}
void insert(int x,int y){
	insert_up(x,y);
	insert_down(x,y);
}
int main(){
	q=read();
	FOR(i,1,q){
		int op=read(),x=read(),y=read();
		if(op==1) insert(x,y);
		else puts(check(x,y)?"YES":"NO");
	}
}