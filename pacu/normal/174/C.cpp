#include <iostream>
#include <vector>
using namespace std;
#define INF 1000000000
#define SEG (1<<17)

int seg[2*SEG],l[2*SEG],r[2*SEG];
int A[100001];
int N;

void init()
{
	A[100000] = INF;
	for(int i=SEG;i<2*SEG;i++)
	{
		if((i-SEG)<N) seg[i] = i-SEG;
		else seg[i] = 100000;
		l[i] = r[i] = i-SEG;
	}
	for(int i=SEG-1;i>0;i--)
	{
		seg[i] = seg[2*i+1];
		if(A[seg[2*i]] < A[seg[2*i+1]])
			seg[i] = seg[2*i];
		l[i] = l[2*i], r[i] = r[2*i+1];
	}
}

int low,high;

int getMin(int i)
{
	if((l[i]>high)||(r[i]<low)) return 100000;
	if((l[i]>=low)&&(r[i]<=high)) return seg[i];
	int a = getMin(2*i);
	int b = getMin(2*i+1);
	if(A[a] < A[b]) return a;
	else return b;
}

vector<pair<int,int> > ans;

void dfs(int a,int b,int dif)
{
	low = a, high = b;
	int c = getMin(1);
	int v = A[c];
	while((v-dif)>0)
	{
//		cout << v << " " << dif << endl;
		ans.push_back(make_pair(a,b));
		dif++;
	}
	if(a<c) dfs(a,c-1,dif);
	if(c<b) dfs(c+1,b,dif);
}

int main()
{
	cin >> N;
	for(int i=0;i<N;i++)
		cin >> A[i];
	init();
	dfs(0,N-1,0);
	cout << ans.size() << "\n";
	for(int i=0;i<ans.size();i++)
		cout << ans[i].first+1 << " " << ans[i].second+1 << "\n";
	return 0;
}