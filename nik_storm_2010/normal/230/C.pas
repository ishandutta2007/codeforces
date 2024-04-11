var
    kol:array[1..100,-1..10001] of longint; ver:array[1..10000] of longint;
      answer,nom,n,m,i,j:longint; sim:char;


function find(nom,c:longint):longint;
var l,r,m:longint;
begin
  l:=0; r:=kol[nom,-1];
  while r-l>1 do
    begin
      m:=(l+r) div 2;
      if kol[nom,m]>c then r:=m else l:=m;
    end;
  if abs(c-kol[nom,l])<abs(c-kol[nom,r]) then find:=kol[nom,l] else find:=kol[nom,r];
end;


begin

  readln(n,m);
  for i:=1 to n do
    begin
      for j:=1 to m do
        begin
          read(sim);
          if sim='1' then begin inc(kol[i,-1]); kol[i,kol[i,-1]]:=j; end;
        end;
      if kol[i,-1]=0 then begin writeln(-1); halt; end else
        begin
          kol[i,0]:=0-(m-kol[i,kol[i,-1]]); kol[i,kol[i,-1]+1]:=m+kol[i,1];
          inc(kol[i,-1]);
        end;
      readln;
    end;
  answer:=maxlongint;
  for j:=1 to m do
    begin
      for i:=1 to n do ver[j]:=ver[j]+abs(j-find(i,j));
      if answer>ver[j] then answer:=ver[j];
    end;
  writeln(answer);

end.