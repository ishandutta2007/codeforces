#include <cstdio>
#include <set>
#include <utility>
#include <vector>
#include <cstdlib>
using namespace std;
const int maxn=65555;
int d[maxn],s[maxn],n;
set<pair<int,int> > st;
vector<int> a1,a2;
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",d+i,s+i);
		st.insert(make_pair(d[i],i));
	}
	while(!st.empty())
	{
		pair<int,int> t=*st.begin();
		int x=t.first,y=t.second;
		st.erase(t);
		if(x!=1)continue;
		t=*st.find(make_pair(d[s[y]],s[y]));
		a1.push_back(y);
		a2.push_back(s[y]);
		st.erase(t);
		t.first--;
		d[s[y]]--;
		d[y]--;
		s[s[y]]^=y;
		s[y]=0;
		st.insert(t);
	}
	printf("%d\n",a1.size());
	for(int i=0;i<a1.size();i++)
		printf("%d %d\n",a1[i],a2[i]);
	return 0;
}