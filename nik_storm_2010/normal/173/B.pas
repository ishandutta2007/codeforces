var
    edge:array[1..2,1..2000000] of longint; start,leng:array[1..2000] of longint;
      q:array[1..1000000] of longint; free,nom,st,en,n,m,i,j,e:longint; sim:char;


procedure addedge(a,b:longint);
begin
  inc(free); edge[1,free]:=b; edge[2,free]:=start[a];
  start[a]:=free;
end;


begin

  readln(n,m); free:=0;
  for i:=1 to n do
    begin
      for j:=1 to m do
        begin
          read(sim);
          if sim='#' then begin addedge(i,j+n); addedge(j+n,i); end;
        end;
      readln;
    end;
  for i:=1 to n+m do leng[i]:=maxlongint; leng[n]:=0;
  st:=1; en:=2; q[1]:=n;
  while st<>en do
    begin
      nom:=q[st]; inc(st); e:=start[nom];
      while e<>0 do
        begin
          if leng[nom]+1<leng[edge[1,e]] then
            begin
              leng[edge[1,e]]:=leng[nom]+1;
              q[en]:=edge[1,e]; inc(en);
            end;
          e:=edge[2,e];
        end;
    end;
  if leng[1]=maxlongint then writeln(-1) else writeln(leng[1]);

end.