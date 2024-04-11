#include <bits/stdc++.h>
struct Splay {
	long long val, add;
	int siz;
	Splay *fa, *ch[2];
};
void do_add(Splay *i, long long v) {
	if(!i) return;
	i->val += v;
	i->add += v;
}
int get_siz(Splay *i) {
	return i ? i->siz : 0;
}
void pushup(Splay *i) {
	i->siz = 1 + get_siz(i->ch[0]) + get_siz(i->ch[1]);
}
void pushdown(Splay *i) {
	if(!i) return;
	do_add(i->ch[0], i->add);
	do_add(i->ch[1], i->add);
	i->add = 0;
}
int type(Splay *i) {
	return i == i->fa->ch[1];
}
void rotate(Splay *i) {
	Splay *f = i->fa;
	int d = type(i);
	if(i->fa = f->fa) f->fa->ch[type(f)] = i;
	if(f->ch[d] = i->ch[!d]) i->ch[!d]->fa = f;
	i->ch[!d] = f, f->fa = i;
	pushup(f);
	pushup(i);
}
Splay *insert(Splay *i, Splay *j, int x) {
	int k = 0;
	while(1) {
		pushdown(i);
		++i->siz;
		if(i->val <= x * (k + get_siz(i->ch[0])+1ll)) {
			if(i->ch[0]) i = i->ch[0]; else {i->ch[0] = j; break;}
		} else {
			k += get_siz(i->ch[0]) + 1;
			if(i->ch[1]) i = i->ch[1]; else {i->ch[1] = j; break;}
		}
	}
	j->fa = i;
	j->val = (k+1ll)*x;
	j->siz = 1;
	while(i = j->fa) {
		if(i->fa) rotate(type(i) == type(j) ? i : j);
		rotate(j);
	}
	return j;
}
long long ans, global;
void print(Splay *i) {
	if(!i) return;
	pushdown(i);
	print(i->ch[0]);
	ans+=i->val;
	if(ans>global) global=ans;
	print(i->ch[1]);
}
Splay node[100000];
int a[100000];
int main() {
	int n, i;
	Splay *root = node;
	scanf("%d", &n);
	for(i = 0; i < n; ++i) scanf("%d", a+i);
	root->val = a[0];
	root->siz = 1;
	for(i = 1; i < n; ++i) {
		root = insert(root, &node[i], a[i]);
		do_add(root->ch[1], a[i]);
	}
	print(root);
	std::cout<<global<<"\n";
	return 0;
}