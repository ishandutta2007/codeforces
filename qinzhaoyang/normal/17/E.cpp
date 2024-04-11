#include <bits/stdc++.h>

using namespace std;

const int N = 2e6 + 10;
typedef long long ll;
const int MOD = 51123987; 

struct Node
{
	int len , num , fail;
	Node() {len = num = fail = 0;}
}	p[N];

int lst = 0 , cnt = 1;

void init()
{
	lst = 0 , cnt = 1;
	p[0].fail = 1 , p[1].len = -1;
}
int first[N] , nxt[N] , to[N] , cur , w[N];

void connect(int x , int y , int z)
{
	++cur;
	to[cur] = y;
	nxt[cur] = first[x];
	w[cur] = z;
	first[x] = cur;
}

int n;
string s;

int get_fail(int x , int y)
{
	while(s[y - p[x].len - 1] != s[y])
		x = p[x].fail;
	return x;
}

void insert(int y)
{
	int np = get_fail(lst , y) , flag = false;
	for(int i = first[np]; i; i = nxt[i])
		if(w[i] == s[y] - 'a' + 1)
		{
			flag = true;
			break;
		}
	if(!flag)
	{
		p[++cnt].len = p[np].len + 2;
		int tmp = get_fail(p[np].fail , y) , temp = 0;
		for(int i = first[tmp]; i; i = nxt[i])
			if(w[i] == s[y] - 'a' + 1)
			{
				temp = to[i];
				break;
			}
		p[cnt].fail = temp;
		p[cnt].num = p[p[cnt].fail].num + 1;
		connect(np , cnt , s[y] - 'a' + 1);
	}
	for(int i = first[np]; i; i = nxt[i])
		if(w[i] == s[y] - 'a' + 1)
		{	
			lst = to[i];
			break;
		}
}

ll sum1[N] , sum2[N] , sum;

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> s , init();
	for(int i = 0; i < n; i++)
		insert(i) , sum1[i] = p[lst].num;

	memset(p , 0 , sizeof p) , memset(first , 0 , sizeof first);
	cur = 0 , init();

	reverse(s.begin() , s.end());
	for(int i = 0; i < n; i++)
		insert(i) , sum2[n - i - 1] = p[lst].num;

	for(int i = n - 1; i >= 0; i--)
		sum2[i] += sum2[i + 1];
	sum = sum2[0];
	if(sum % 2 == 0)
		sum = ((sum / 2) % MOD * ((sum - 1) % MOD)) % MOD;
	else
		sum = ((sum - 1) / 2) % MOD * (sum % MOD) % MOD;
	for(int i = 0; i < n; i++)
		sum1[i] %= MOD , sum2[i] %= MOD;
	for(int i = 0; i < n - 1; i++)
		sum = ((sum - sum1[i] * sum2[i + 1]) % MOD + MOD) % MOD;
	cout << sum << endl;
	return 0;
}