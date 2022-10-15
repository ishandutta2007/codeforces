
var
  a, b, c, d, f, x, g : longint;
  
begin
  read(a, b, c, d);
  f := 3 * a div 10;
  x := a - a div 250 * c;
  if f < x then f := x;
  g := 3 * b div 10;
  x := b - b div 250 * d;
  if g < x then g := x;
  if f > g then 
    writeln('Misha')
  else if f < g then
    writeln('Vasya')
  else
    writeln('Tie');
end.