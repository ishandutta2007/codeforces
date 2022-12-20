#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

long long base[500000];		//[university] -> students: base of university
vector<int> ulist[500000];	//[university] -> dorms: list of dorms in university
vector<int> uperm[500000];	//[university] -> query #: queries when base changes
vector<long long> upBase[500000];	//[university] -> students: base[university] at given query #

vector<int> mlist[500000];	//[military] -> dorms: list of dorms in military
int baseClear[500000];		//[military] -> query #: update for when dorms last cleared
int updateLen[500000];		//number of dorms in list which update applies to



int uni[500000];	//[dorm] -> [university]: university that it belongs to
int mil[500000];	//[dorm] -> [military]: military that it belongs to

long long dif[500000];	//[dorm] -> students: difference between students in dorm and base of university
vector<int> dperm[500000];	//[dorm] -> query #: queries when uni & dif change
vector<int> dpUni[500000];	//[dorm] -> [university]: uni[dorm] at given query #
vector<long long> dpDif[500000];	//[dorm] -> students: dif[dorm] at given query #

int clear[500000];			//[dorm] -> query #: last time dorm cleared, subject to update
int mpos[500000];			//[dorm] -> index: the location in mlist of this dorm

void mergeUni(int a,int b,int qnum)
{
	a = uni[a], b = uni[b];
	if(ulist[a].size() > ulist[b].size())
		swap(a,b);
	int cur;
	for(int i=0;i<ulist[a].size();i++)
	{
		cur = ulist[a][i];
		dif[cur] = base[a] + dif[cur] - base[b];
		uni[cur] = b;
		dperm[cur].push_back(qnum);
		dpUni[cur].push_back(uni[cur]);
		dpDif[cur].push_back(dif[cur]);
		ulist[b].push_back(cur);
	}
	ulist[a].clear();
}

void mergeMil(int a,int b,int qnum)
{
	a = mil[a], b = mil[b];
	if(mlist[a].size() > mlist[b].size())
		swap(a,b);
	int cur;
	int oldsz = mlist[b].size();
	for(int i=0;i<mlist[a].size();i++)
	{
		cur = mlist[a][i];
		if(i < updateLen[a])
			clear[cur] = max(clear[cur], baseClear[a]);
		mil[cur] = b;
		mpos[cur] += oldsz;
		mlist[b].push_back(cur);
	}
	mlist[a].clear();
}

void moveIn(int a,int qnum)
{
	a = uni[a];
	base[a] += ulist[a].size();
	uperm[a].push_back(qnum);
	upBase[a].push_back(base[a]);
}

void raid(int a,int qnum)
{
	a = mil[a];
	baseClear[a] = qnum;
	updateLen[a] = mlist[a].size();
}

long long query(int cur,int qnum)
{
	int cdate = clear[cur];
	if(mpos[cur] < updateLen[mil[cur]])
		cdate = max(cdate,baseClear[mil[cur]]);
	int a = uni[cur];
	long long ans = base[a] + dif[cur];
	if(cdate > -1)
	{
		int dpermloc = lower_bound(dperm[cur].begin(),dperm[cur].end(),cdate) - dperm[cur].begin() - 1;
		ans -= dpDif[cur][dpermloc];
		int olda = dpUni[cur][dpermloc];
		int upermloc = lower_bound(uperm[olda].begin(),uperm[olda].end(),cdate) - uperm[olda].begin() - 1;
		ans -= upBase[olda][upermloc];
	}
	return ans;
}

int main()
{
	int N,Q;
	scanf("%d %d",&N,&Q);
	for(int i=0;i<N;i++)
	{
		ulist[i].push_back(i);
		uperm[i].push_back(0);
		upBase[i].push_back(0);
		mlist[i].push_back(i);
		baseClear[i] = -1;
		updateLen[i] = 0;
		uni[i] = i;
		mil[i] = i;
		dif[i] = 0;
		dperm[i].push_back(0);
		dpUni[i].push_back(i);
		dpDif[i].push_back(0);
		clear[i] = -1;
		mpos[i] = 0;
	}
	char tp;
	int a,b;
	for(int i=0;i<Q;i++)
	{
		scanf(" %c ",&tp);
		if(tp == 'U')
		{
			scanf("%d %d",&a,&b);
			mergeUni(a-1,b-1,i+1);
		}
		else if(tp == 'M')
		{
			scanf("%d %d",&a,&b);
			mergeMil(a-1,b-1,i+1);
		}
		else if(tp == 'A')
		{
			scanf("%d",&a);
			moveIn(a-1,i+1);
		}
		else if(tp == 'Z')
		{
			scanf("%d",&a);
			raid(a-1,i+1);
		}
		else
		{
			scanf("%d",&a);
			printf("%I64d\n",query(a-1,i+1));
		}
	}
}