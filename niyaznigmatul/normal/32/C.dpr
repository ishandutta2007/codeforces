var n, m, s, a, b : int64;

begin
read(n, m, s);
a := n mod s;
b := m mod s;
if (a = 0) then a := s;
if (b = 0) then b := s;
n := (n + s - 1) div s * s;
m := (m + s - 1) div s * s;
writeln(n div s * (m div s) * (a * b));
end.