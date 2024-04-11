var
    s:string;
     d,i,j:longint;



begin

  readln(s);
   d:=length(s);
  s:=s+'   ';

  i:=1;
   while i<=d do
    if (s[i]='W') and (s[i+1]='U') and (s[i+2]='B')
     then
      begin
       i:=i+3;
      end
     else
      begin
       while i<=d do
        begin
         write(s[i]); inc(i);
          if (s[i]='W') and (s[i+1]='U') and (s[i+2]='B')
           then
           begin
            write(' ');
            break;
           end;
        end;
      end;

end.