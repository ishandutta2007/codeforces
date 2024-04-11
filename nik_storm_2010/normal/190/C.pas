var
  a:array[1..100000] of ansistring; s,ans:ansistring;
  l:array[1..100000] of longint; i,j,n,d,size:longint;


procedure error;
begin
  writeln('Error occurred');
  halt;
end;


begin

  readln(n);
  readln(s); d:=length(s);
  j:=1; ans:='';
  for i:=1 to d do if s[i]=' ' then inc(j) else a[j]:=a[j]+s[i];
  if n=1 then
  begin
    if (j=1) and (a[1]='int') then ans:='int' else error;
  end
    else
  begin
    if a[1]='int' then error;
    size:=1; l[size]:=2; ans:='pair<';
    for i:=2 to j do
    begin
      if a[i]='int' then
      begin
        if size=0 then error;
        if l[size]=2 then ans:=ans+a[i];
        if l[size]=1 then ans:=ans+','+a[i];
        dec(l[size]);
      end
        else
      begin
        if size=0 then error;
        if l[size]=2 then ans:=ans+a[i]+'<';
        if l[size]=1 then ans:=ans+','+a[i]+'<';
        dec(l[size]); inc(size); l[size]:=2;
      end;
      while (size>0) and (l[size]=0) do begin ans:=ans+'>'; dec(size); end;
    end;
  end;
  if size=0 then writeln(ans) else error;

end.