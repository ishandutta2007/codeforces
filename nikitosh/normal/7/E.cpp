#include <bits/stdc++.h> 

using namespace std;
 
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sz(x) (int) ((x).size()) 
#define forn(i, n) for (int i = 0; (i) < (n); ++i)
#define fornr(i, n) for (int i = (n) - 1; (i) >= 0; --i)
#define forab(i, a, b) for (int i = (a); (i) < (b); ++i)
#define forba(i, a, b) for (int i = (b) - 1; (i) >= (a); --i)
#define forit(it, c) for (__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define all(c) (c).begin(), (c).end() 

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) static_cast<void>(0)   
#endif

#ifdef _WIN32
	#define I64 "%I64d"
#else
	#define I64 "%lld"
#endif

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef unsigned int uint;
typedef vector <int> vi;
typedef pair <int, int> pii;

#define FNAME ""

enum Operation {PLUS, MINUS, MUL, DIV, LEAF};
map<char, Operation> op = {{'+', PLUS}, {'-', MINUS}, {'*', MUL}, {'/', DIV}};

struct Node {
	Node *l, *r;
	Operation operation;
	bool isSafe;
	bool isSuspicious;
	bool isChecked;
	Node(Operation operation): l(NULL), r(NULL), operation(operation), isSafe(0), isSuspicious(0), isChecked(0) {}	
	Node(Node *l, Node *r, Operation operation): l(l), r(r), operation(operation), isSafe(0), isSuspicious(0), isChecked(0) {}	
};

map<string, Node*> m;

void skipSpaces(const string &s, int &index) {
 	while (isspace(s[index]))
 		index++;
}

Node* readExpression(const string &s, int &index);

Node* readToken(const string &s, int &index) {
    skipSpaces(s, index);
 	if (isdigit(s[index])) {
 		while (isdigit(s[index]))
 			index++;
		return new Node(LEAF);
	}
 	if (isalpha(s[index])) {
 		string t = "";
 		while (isalpha(s[index]))
 			t.pb(s[index++]);
 		if (m.count(t))
 			return m[t];
		return new Node(LEAF);
	}
	assert(s[index] == '(');
	index++;
	Node *node = new Node(*readExpression(s, index));
	assert(s[index++] == ')');
 	node->isSafe = 1;
	return node;
}

Node* readExpression(const string &s, int &index) {
    vector<Node*> nodes;
    vector<Operation> operations;
    Node *node = readToken(s, index);
    nodes.pb(node);
	skipSpaces(s, index);
	while (index < sz(s) && s[index] != ')') {
		char c = s[index++];
		assert(op.count(c));
		Operation operation = op[c];
        Node *node = readToken(s, index);
		if (operation == MUL || operation == DIV) {
		 	Node *nodeL = nodes.back();
		 	nodes.pop_back();
		 	nodes.pb(new Node(nodeL, node, operation));
		}
		else {
			if (sz(nodes) != 1) {
			 	Node *nodeL = nodes[0], *nodeR = nodes[1];
			 	nodes.clear();
			 	nodes.pb(new Node(nodeL, nodeR, operations[0]));
			 	operations.clear();
			}
		 	nodes.pb(node);
		 	operations.pb(operation);
		}
		skipSpaces(s, index);
	}	
	assert(sz(nodes) <= 2);
	if (sz(nodes) == 2)
		return new Node(nodes[0], nodes[1], operations[0]);
	return nodes[0];
}

bool isUnsafePlusOrMinus(Node *root) {
 	return !root->isSafe && (root->operation == MINUS || root->operation == PLUS);
}

void check(Node *root) {
    if (!root || root->isChecked)
		return;
	root->isChecked = 1;
	if (root->operation == LEAF)
		return;
	check(root->l);
	check(root->r);
	if (root->l->isSuspicious || root->r->isSuspicious)
		root->isSuspicious = 1;
	switch (root->operation) {
	 	case PLUS:
	 		break;
	 	case MINUS:
	 		root->isSuspicious |= isUnsafePlusOrMinus(root->r);
	 		break;
	 	case MUL:
	 		root->isSuspicious |= isUnsafePlusOrMinus(root->l);
	 		root->isSuspicious |= isUnsafePlusOrMinus(root->r);
	 		break;
	 	case DIV:
	 		root->isSuspicious |= (!root->r->isSafe && root->r->operation != LEAF);
	 		root->isSuspicious |= isUnsafePlusOrMinus(root->l);
	 		break;
	 	default:
	 		assert(0);
	}
}

int main() {
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    
	
	int n;
	string s, t;
	scanf("%d\n", &n);
	forn (i, n) {
		cin >> s;
		if (s.length() == 1)
			cin >> s;
		cin >> s;
		getline(cin, t);
		int index = 0;
		m[s] = readExpression(t, index);
		check(m[s]);
	}
	getline(cin, t);
	int index = 0;
	Node *root = readExpression(t, index);
	check(root);
	if (root->isSuspicious)
		puts("Suspicious");
	else
		puts("OK");		
	return 0;
}