#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Node {int id; double v; Node(int id = 0 , double v = 0.0) : id(id) , v(v){}};
bool operator < (Node a , Node b) {return a.v > b.v;}

const int N = 100010;

int k , n , m;
ll x[N];
int a[N] , b[N] , c[N]; 
Node op1[N];
vector <Node> op2 , op3;
vector <int> Ans;

bool cmp(int A , int B)
{
	if(a[A] != a[B])
		return a[A] < a[B];
	return c[A] < c[B];
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> k >> n >> m;
	for(int i = 1; i <= k; i++)
		cin >> x[i];
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i] >> b[i] >> c[i];
		if(a[i] == 1)
		{
			if(c[i] > op1[b[i]].v)
				op1[b[i]] = Node(i , (double)c[i]);
		}
		else if(a[i] == 2)
			op2.push_back(Node(i , (double)c[i]));
		else
			op3.push_back(Node(i , (double)c[i]));
	}
	for(int i = 1; i <= k; i++)
		if(op1[i].v > x[i])
			op2.push_back((Node){op1[i].id , op1[i].v - x[i]});
	sort(op2.begin() , op2.end());
	for(int i = 0; i < op2.size(); i++)
	{
		op3.push_back(Node(op2[i].id , (x[b[op2[i].id]] + op2[i].v) * 1.0 / x[b[op2[i].id]]));
		x[b[op2[i].id]] += op2[i].v;
	}
	sort(op3.begin() , op3.end());
	for(int i = 0; i < min((int)op3.size() , m); i++)
		Ans.push_back(op3[i].id);
	sort(Ans.begin() , Ans.end() , cmp);
	cout << Ans.size() << endl;
	for(int i = 0; i < Ans.size(); i++)
		cout << Ans[i] << " ";
	cout << endl; 
	return 0;
}