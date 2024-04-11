var
    s : string;
    n : longint;


procedure inputdata;
 begin
  assign(input,'input.txt');
   reset(input);
    readln(s);
     readln(n);
  close(input);
 end;

Begin

  inputdata;
   assign(output,'output.txt');
    rewrite(output);
     if ((s='front') and (n=1)) or ((s='back') and (n=2))
      then writeln('L')
       else writeln('R');
  close(output);

End.