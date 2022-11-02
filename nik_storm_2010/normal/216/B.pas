var
    g:array[0..2,1..100] of longint; used:array[1..100] of boolean;
     answer,leng,n,m,i,x,y:longint; cycle:boolean;


procedure find(nom,pred:longint);
  var i:longint;
begin
  inc(leng); used[nom]:=true;
  for i:=1 to g[0,nom] do
    begin
      if (used[g[i,nom]]=true) and (g[i,nom]<>pred) then cycle:=true;
      if used[g[i,nom]]=false then
        begin
          find(g[i,nom],nom);
        end;
    end;
end;


begin

  readln(n,m);
  for i:=1 to m do
    begin
      readln(x,y);
      inc(g[0,x]); g[g[0,x],x]:=y;
      inc(g[0,y]); g[g[0,y],y]:=x;
    end;
  answer:=0;

  for i:=1 to n do
    if used[i]=false then
      begin
        leng:=0; cycle:=false; find(i,0);
        if (cycle=true) and (leng mod 2 = 1) then
          begin
            inc(answer);
          end;
      end;
    if (n-answer) mod 2=1 then inc(answer);
  writeln(answer);

end.