uses
  math;
const
  lim=200000;
var
  st:array[0..lim] of char;
  sum,left:array[0..lim] of longint;
  size,ans,d,i,l,r:longint;
  s:ansistring;

begin
  readln(s);
  d:=length(s);
  ans:=0; l:=1; r:=0;
  for i:=1 to d do if (s[i] in ['(','[']) then
  begin
    inc(size);
    st[size]:=s[i];
    if (left[size]=0) then left[size]:=i;
  end
  else
  begin
    if (s[i]=')') then
    begin
      if (st[size]='(') then
      begin
        sum[size]:=sum[size]+sum[size+1];
        sum[size+1]:=0;
        left[size+1]:=0;
        if (ans<sum[size]) then begin ans:=sum[size]; l:=left[size]; r:=i; end;
        dec(size);
      end
      else
      begin
        inc(size);
        st[size]:=s[i];
      end;
    end
    else
    begin
      if (st[size]='[') then
      begin
        sum[size]:=sum[size]+sum[size+1]+1;
        sum[size+1]:=0;
        left[size+1]:=0;
        if (ans<sum[size]) then begin ans:=sum[size]; l:=left[size]; r:=i; end;
        dec(size);
      end
      else
      begin
        inc(size);
        st[size]:=s[i];
      end;
    end;
  end;
  writeln(ans);
  for i:=l to r do write(s[i]);
end.