#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
using namespace std;

typedef long long LL;

int man_size, bug_size;
LL pas_max;

struct Bug {
    int id;
    LL comp;
    Bug(){}
    Bug(int id, LL c) : id(id), comp(c){}
} bug[100010];
bool bug_LT(const Bug&a, const Bug&b) {
    return a.comp < b.comp;
}

struct Man {
    int id;
    LL abi, pas;
    Man(){}
    Man(int id, LL a, LL p) : id(id), abi(a), pas(p) {}
} man[100010];
bool man_LT(const Man&a, const Man&b) {
    return a.abi < b.abi;
}
bool operator<(const Man&a, const Man&b) {
    return a.pas > b.pas; // GT
}


void input() {
    int t;
    scanf("%d%d%d", &man_size, &bug_size, &t);
    pas_max = t;
    for (int i=0; i<bug_size; i++) {
	scanf("%d", &t);
	bug[i].id = i;
	bug[i].comp = t;
    }
    for (int i=0; i<man_size; i++) {
	scanf("%d", &t);
	man[i].id = i;
	man[i].abi = t;
    }
    for (int i=0; i<man_size; i++) {
	scanf("%d", &t);
	man[i].pas = t;
    }
}

bool NO() {
    int abi_max_id = 0;
    for (int i=0; i<man_size; i++)
	if (man[abi_max_id].abi < man[i].abi) abi_max_id = i;

    int bug_max_id = 0;
    for (int i=0; i<bug_size; i++)
	if (bug[bug_max_id].comp < bug[i].comp) bug_max_id = i;

    if (man[abi_max_id].abi < bug[bug_max_id].comp) return true;

    for (int i=0; i<man_size; i++)
	if (man[i].abi >= bug[bug_max_id].comp && man[i].pas <= pas_max) return false;

    return true;
}

int who_fix[100010];

bool OK(int day) {
    vector<int>v;
    {
	int tmp = bug_size;
	while (tmp) {
	    int g = min(day, tmp);
	    v.push_back(g);
	    tmp -= g;
	}
    }

    
    int bug_rest = bug_size;
    int man_rest = man_size;
    priority_queue<Man> Q;

    LL pas_sum = 0;
    for (int i=0; i<(int)v.size(); i++) {
	int comp = bug[bug_rest - 1].comp;

	while (man_rest && man[man_rest - 1].abi >= comp) {
	    Q.push(man[man_rest - 1]);
	    man_rest--;
	}

	if (Q.empty()) return false;
	Man m = Q.top();
	Q.pop();
	pas_sum += m.pas;

	for (int j=0; j<v[i]; j++) {
	    who_fix[bug[bug_rest - 1].id] = m.id;
	    bug_rest--;
	}
    }
    
    return (pas_sum <= pas_max);
}

int main() {
    input();

    if (NO()) { puts("NO"); return 0; }
    puts("YES");

    sort(bug, bug+bug_size, bug_LT);
    sort(man, man+man_size, man_LT);

    

    int l=0, r=bug_size;
    for (; r-l>1;) {
	int day=(r+l)/2;
	if (OK(day)) r=day;
	else l=day;
    }

    OK(r);
    for (int i=0; i<bug_size; i++) {
	if (i) putchar(' ');
	printf("%d", who_fix[i]+1);
    }
    putchar('\n');

    return 0;
}