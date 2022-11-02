var
    a:array[1..100000] of longint; moment,time,nom,c,t,i,n,m:longint;


procedure dichotomy(tek:longint; var nom:longint);
var l,r,m:longint;
begin
  l:=1; r:=n;
  while r-l>1 do
    begin
      m:=(r+l) div 2;
      if a[m]>tek then r:=m else l:=m;
    end;
  if a[r]<=tek then nom:=r else nom:=l;
end;


begin

  readln(n,m); time:=1;
  for i:=1 to n do
    begin
      readln(c,t);
      a[i]:=time; time:=time+c*t;
    end;
  for i:=1 to m do
    begin
      read(moment); dichotomy(moment,nom);
      writeln(nom);
    end;

end.