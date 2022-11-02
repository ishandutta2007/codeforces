var
    a:array[0..1001] of char; fr,lr,fl,ll,n,i:longint;


begin

  readln(n); fr:=-1; lr:=-1; fl:=-1; ll:=-1;
  for i:=1 to n do read(a[i]);
  for i:=1 to n do
    begin
      if (i<>1) and (a[i]='R') and (a[i-1]<>'R') then fr:=i;
      if (i<>n) and (a[i]='R') and (a[i+1]<>'R') then lr:=i;
      if (i<>1) and (a[i]='L') and (a[i-1]<>'L') then fl:=i;
      if (i<>n) and (a[i]='L') and (a[i+1]<>'L') then ll:=i;
    end;
  if (fr=-1) then writeln(ll,' ',fl-1) else
  if (fl=-1) then writeln(fr,' ',lr+1) else writeln(fr,' ',lr);

end.