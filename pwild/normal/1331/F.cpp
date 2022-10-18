#include <bits/stdc++.h>
using namespace std;

const std::vector<std::string> elements = { 
    "H",  "He", "Li", "Be", "B",  "C",  "N",  "O",  "F",  "Ne",
    "Na", "Mg", "Al", "Si", "P",  "S",  "Cl", "Ar", "K",  "Ca",
    "Sc", "Ti", "V",  "Cr", "Mn", "Fe", "Co", "Ni", "Cu", "Zn",
    "Ga", "Ge", "As", "Se", "Br", "Kr", "Rb", "Sr", "Y",  "Zr",
    "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn",
    "Sb", "Te", "I",  "Xe", "Cs", "Ba", "La", "Ce", "Pr", "Nd",
    "Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb",
    "Lu", "Hf", "Ta", "W",  "Re", "Os", "Ir", "Pt", "Au", "Hg",
    "Tl", "Pb", "Bi", "Po", "At", "Rn", "Fr", "Ra", "Ac", "Th",
    "Pa", "U",  "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es", "Fm",
    "Md", "No", "Lr", "Rf", "Db", "Sg", "Bh", "Hs", "Mt", "Ds",
    "Rg", "Cn", "Nh", "Fl", "Mc", "Lv", "Ts", "Og"};

bool can_add(string &word, int i, string elem) {
	elem[0] = tolower(elem[0]);
	return word.substr(i,elem.size()) == elem;
}

int main() {
	string word;
	cin >> word;
	for (char &c: word) c = tolower(c);
	
	int n = word.size();

	vector<int> possible(n+1);
	possible[n] = true;
	
	for (int i = n-1; i >= 0; i--) {
		for (string elem: elements) {
			possible[i] |= can_add(word,i,elem) && possible[i+elem.size()];
		}
	}
	
	if (!possible[0]) {
		cout << "NO" << endl;
		return 0;
	}
	
	cout << "YES" << endl;
	return 0;
}