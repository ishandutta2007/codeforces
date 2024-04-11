#include <stdio.h>
#include <algorithm>
#include <set>
#include <vector>
#define MN 2000

int n,m,mx[MN+5];

struct point{
	int x,y;
}a[MN+5],b[MN+5];

std::vector<point> c;

struct data{
	int aid,bid,dis;
};

std::vector<data> d;

std::multiset<int> s;

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&a[i].x,&a[i].y);
	for(int i=1;i<=m;i++)
		scanf("%d%d",&b[i].x,&b[i].y);
	std::sort(b+1,b+1+m,[](point a,point b)->bool{
		if(a.x!=b.x)
			return a.x<b.x;
		else
			return a.y<b.y;
	});
	for(int i=m;i>=1;i--)
		if(c.empty()||b[i].y>c.back().y)
			c.push_back(b[i]);
	for(int i=1;i<=n;i++){
		for(int j=0;j<(int)c.size();j++){
			if(a[i].x>c[j].x||a[i].y>c[j].y) continue;
			d.push_back((data){i,j,c[j].x+1-a[i].x});
			mx[i] = std::max(mx[i],c[j].y+1-a[i].y);
		}
	}
	std::sort(d.begin(),d.end(),[](data a,data b)->bool{
		return a.dis < b.dis;
	});
	for(int i=1;i<=n;i++){
		if(mx[i]>0)
			s.insert(mx[i]);
	}
	int ans = 0;
	if(s.begin()!=s.end()){
		ans += *(--s.end());
	}
	for(auto dt:d){
		if(mx[dt.aid]>0){
			s.erase(s.find(mx[dt.aid]));
		}
		if(dt.bid>0){
			mx[dt.aid] = std::max((c[dt.bid-1].y+1)-a[dt.aid].y,0);
		}else{
			mx[dt.aid] = 0;
		}
		if(mx[dt.aid]>0){
			s.insert(mx[dt.aid]);
		}
		int tans = dt.dis;
		if(s.end()!=s.begin()){
			tans += *(--s.end());
		}
		ans = std::min(ans,tans);
	}
	printf("%d\n",ans);
}