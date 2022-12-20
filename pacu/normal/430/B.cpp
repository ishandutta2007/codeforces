#include <iostream>
#include <vector>
using namespace std;

struct Node
{
	int cnt;
	int col;
	Node *next;
	Node *prev;
};

Node *head;

void ins(int cnt,int col)
{
	Node *x = new Node;
	x->cnt = cnt;
	x->col = col;
	x->prev = NULL;
	x->next = head;
	if(x->next != NULL)
		x->next->prev = x;
	head = x;
}

int dest;

void del(Node *x)
{
	if(x->prev != NULL)
		x->prev->next = x->next;
	else
		head = x->next;
	if(x->next != NULL)
		x->next->prev = x->prev;
	free(x);
}

bool join(Node *x)
{
	if(x->next == NULL)
		return 0;
	if(x->col != x->next->col)
		return 0;
	x->cnt += x->next->cnt;
	del(x->next);
	return 1;
}

void rem()
{
	Node *x = head;

	while(x != NULL)
	{
		do ; while(join(x));
		if(x->cnt>=3)
		{
			dest += x->cnt;
			if(x->prev != NULL)
			{
				x = x->prev;
				del(x->next);
			}
			else if(x->next != NULL)
			{
				x = x->next;
				del(x->prev);
			}
			else
			{
				del(x);
				return;
			}
		}
		else
			x = x->next;
	}
}

int main()
{
	int N,K,X;
	int i,j;
	vector<int> cnt;
	vector<int> col;
	cin >> N >> K >> X;
	cin >> j;
	cnt.push_back(1);
	col.push_back(j);
	for(i=1;i<N;i++)
	{
		cin >> j;
		if(j==col[col.size()-1])
			cnt[cnt.size()-1]++;
		else
		{
			cnt.push_back(1);
			col.push_back(j);
		}
	}
	int mx = 0;
	for(j=0;j<cnt.size();j++)
	{
		if(X != col[j])
			continue;
		head = NULL;
		cnt[j]++;
		for(i=0;i<cnt.size();i++)
			ins(cnt[i],col[i]);
		cnt[j]--;
		dest = 0;
		rem();
		mx = max(mx,dest);
	}
	cout << max(mx-1,0) << endl;
}