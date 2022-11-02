#include <math.h>
#include <vector>
#include <stdio.h>
#include <assert.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
struct Node
{
	char set;
	int max, cnt;
	Node *trans[2], *parent;
	std::vector<Node *> prev;
};
const int P=1e9+7;
Node pool[6000], *mem=pool, *p[3001];
Node *ext(Node *root, Node *p, int c) {
	Node *i=mem++, *q, *r;
	i->max=p->max;
	for(; p && !p->trans[c]; p=p->parent) p->trans[c]=i;
	if(!p) {
		i->parent=root;
		return i;
	}
	q=p->trans[c];
	if(q->max==p->max+1) {
		i->parent=q;
		return i;
	}
	r=mem++;
	*r=*q;
	r->max=p->max+1;
	i->parent=q->parent=r;
	for(; p && p->trans[c]==q; p=p->parent) p->trans[c]=r;
	return i;
}
#define L ->trans[0]
#define Y ->trans[1]
int main()
{
	int m, i, ans=0;
	Node *root=mem++, *q;
	scanf("%d", &m);
	p[0]=root;
	for(i=1; i<=m; ++i) {
		int x;
		scanf("%d", &x);
		p[i]=ext(root, p[i-1], x);
	}
	for(q=pool; q!=mem; ++q) {
		Node *l1, *l2, *l3, *l4;
		if(l1=q L) {
			l1->prev.push_back(q);
			if(l2=l1 L) {
				l2->prev.push_back(q);
				if(l3=l2 L) {
					l3->prev.push_back(q);
					if(l4=l3 L) l4->prev.push_back(q);
					if(l4=l3 Y) l4->prev.push_back(q);
				}
				if(l3=l2 Y) {
					l3->prev.push_back(q);
					if(l4=l3 L) l4->prev.push_back(q);
				}
			}
			if(l2=l1 Y) {
				l2->prev.push_back(q);
				if(l3=l2 L) {
					l3->prev.push_back(q);
					if(l4=l3 L) l4->prev.push_back(q);
				}
				if(l3=l2 Y) {
					l3->prev.push_back(q);
					if(l4=l3 L) l4->prev.push_back(q);
					if(l4=l3 Y) l4->prev.push_back(q);
				}
			}
		}
		if(l1=q Y) {
			l1->prev.push_back(q);
			if(l2=l1 L) {
				l2->prev.push_back(q);
				if(l3=l2 L) {
					l3->prev.push_back(q);
					if(l4=l3 L) l4->prev.push_back(q);
					if(l4=l3 Y) l4->prev.push_back(q);
				}
				if(l3=l2 Y) {
					l3->prev.push_back(q);
					if(l4=l3 L) l4->prev.push_back(q);
					if(l4=l3 Y) l4->prev.push_back(q);
				}
			}
			if(l2=l1 Y) {
				l2->prev.push_back(q);
				if(l3=l2 L) {
					l3->prev.push_back(q);
					if(l4=l3 L) l4->prev.push_back(q);
					if(l4=l3 Y) l4->prev.push_back(q);
				}
				if(l3=l2 Y) l3->prev.push_back(q);
			}
		}
	}
	root->set=1;
	root->cnt=1;
	for(i=1; i<=m; ++i) {
		for(q=p[i]; q && !q->set; q=q->parent) {
			q->set=1;
			for(Node *pr: q->prev) q->cnt=(q->cnt+pr->cnt)%P;
			ans=(ans+q->cnt)%P;
		}
		printf("%d\n", ans);
	}
	return 0;
}