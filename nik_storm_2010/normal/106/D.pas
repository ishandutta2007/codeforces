var
    a:array[1..1000,1..1000] of char; sim:array[1..100000] of char; len:array[1..100000] of longint;
     may:array[1..4,1..1000,1..1000] of longint; d:array[1..2,65..90] of longint;
      n,m,i,j,k,x,y:longint; have,tek:boolean;


procedure createmassiv;
  var i,j:longint;
begin
  for i:=1 to n do
    for j:=1 to m do
      begin
        if a[i,j]='#' then begin may[1,i,j]:=0; may[2,i,j]:=0; end
          else
          begin
            if a[i-1,j]='#' then may[1,i,j]:=0 else may[1,i,j]:=may[1,i-1,j]+1;
            if a[i,j-1]='#' then may[2,i,j]:=0 else may[2,i,j]:=may[2,i,j-1]+1;
          end;
      end;
  for i:=n downto 1 do
    for j:=m downto 1 do
      begin
        if a[i,j]='#' then begin may[3,i,j]:=0; may[4,i,j]:=0; end
          else
          begin
            if a[i+1,j]='#' then may[3,i,j]:=0 else may[3,i,j]:=may[3,i+1,j]+1;
            if a[i,j+1]='#' then may[4,i,j]:=0 else may[4,i,j]:=may[4,i,j+1]+1;
          end;
      end;
end;


begin

  readln(n,m);
  for i:=1 to n do
    begin
      for j:=1 to m do
        begin
          read(a[i,j]);
          if (a[i,j]<>'.') and (a[i,j]<>'#') then
            begin
              d[1,ord(a[i,j])]:=i;
              d[2,ord(a[i,j])]:=j;
            end;

        end;
      readln;

    end;
  readln(k);
  for i:=1 to k do
    begin
      read(sim[i]); readln(len[i]);
    end;
  createmassiv;

  have:=false;
  for i:=65 to 90 do
    begin
      if d[1,i]<>0 then
        begin
          x:=d[1,i]; y:=d[2,i]; tek:=true;
          for j:=1 to k do
            begin
              if sim[j]='N' then
                begin
                  if may[1,x,y]>=len[j] then begin x:=x-len[j]; end
                    else begin tek:=false; break; end;
                end;
              if sim[j]='W' then
                begin
                  if may[2,x,y]>=len[j] then begin y:=y-len[j]; end
                    else begin tek:=false; break; end;
                end;
              if sim[j]='S' then
                begin
                  if may[3,x,y]>=len[j] then begin x:=x+len[j]; end
                    else begin tek:=false; break; end;
                end;
              if sim[j]='E' then
                begin
                  if may[4,x,y]>=len[j] then begin y:=y+len[j]; end
                    else begin tek:=false; break; end;
                end;
            end;
          if tek=true then begin write(chr(i)); have:=true; end;
        end;
    end;
  if have=false then writeln('no solution');

end.