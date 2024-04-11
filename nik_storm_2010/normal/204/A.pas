var
  a,step:array[-1..18] of int64; l,r:int64;


function solve(x:int64):int64;
var l,res:int64; i,j:longint;
begin
  res:=0; if (x<=9) then exit(x);
  step[0]:=1; step[-1]:=1; for i:=1 to 18 do step[i]:=step[i-1]*10;
  fillchar(a,sizeof(a),0); l:=0;
  while (x<>0) do
  begin
    inc(l); a[l]:=x mod 10;
    x:=x div 10;
  end;
  for i:=1 to l-1 do res:=res+step[i-2]*9;
  for i:=l downto 2 do for j:=0 to 9 do
  begin
    if (i=l) and (j=0) then continue;
    if (j<a[i]) then res:=res+step[i-2] else break;
  end;
  if a[l]<=a[1] then inc(res);
  solve:=res;
end;


begin
  readln(l,r);
  writeln(solve(r)-solve(l-1));
end.